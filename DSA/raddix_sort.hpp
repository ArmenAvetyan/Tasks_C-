#pragma once
#include <ranges>
#include <vector>

template <std::ranges::random_access_range Container>
void counting_sort_rad(Container& c, int exp) {
    std::vector<int> count (10);

    for(auto x : c)
        ++count[x / exp % 10];

    for(int i {1}; i < 10; ++i)
        count[i] += count[i - 1];

    Container out (c.size());

    for(auto It {c.rbegin()}; It != c.rend(); ++It)
        out[--count[*It / exp % 10]] = *It;

    std::ranges::move(out, c.begin());
}

template <std::ranges::random_access_range Container>
    requires std::integral<std::ranges::range_value_t<Container>>
void raddix_sort(Container& c) {
    if(std::ranges::empty(c)) return;

    auto k {*std::ranges::max_element(c)};

    for(int exp {1}; k / exp > 0; exp *= 10)
        counting_sort_rad(c, exp);
}

template <std::ranges::random_access_range Container>
void counting_sort_rad256(Container& c, int sh) {
    std::vector<int> count (256);

    for(auto x : c)
        ++count[(x >> sh) & 0xFF];

    for(int i {1}; i < 256; ++i)
        count[i] += count[i - 1];

    Container out (c.size());

    for(auto It {c.rbegin()}; It != c.rend(); ++It)
        out[--count[(*It >> sh) & 0xFF]] = *It;

    std::ranges::move(out, c.begin());
}

template <std::ranges::random_access_range Container>
    requires std::integral<std::ranges::range_value_t<Container>>
void raddix_sort256(Container& c) {
    if(std::ranges::empty(c)) return;

    constexpr int bits {sizeof(std::ranges::range_value_t<Container>) * 8};

    for(int sh {}; sh < bits; sh += 8)
        counting_sort_rad256(c, sh);
}

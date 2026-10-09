#pragma once
#include <algorithm>
#include <ranges>
#include <vector>
#include <cstddef>

template <std::ranges::random_access_range Container>
    requires std::integral<std::ranges::range_value_t<Container>>
void counting_sort(Container& c) {
    if(std::ranges::empty(c)) return;

    auto [min_it, max_it] = std::ranges::minmax_element(c);

    auto min_e {*min_it};
    auto max_e {*max_it};
    auto range {static_cast<long long>(max_e) - static_cast<long long>(min_e) + 1LL};

    if(range > c.size() * 10) {
        std::ranges::sort(c);
        return;
    }

    std::vector<std::size_t> count (range);

    for(auto x : c) ++count[x - min_e];

    for (std::size_t i {1}; i < count.size(); ++i)
        count[i] += count[i - 1];

    Container out (c.size());

    for (auto It {c.rbegin()}; It != c.rend(); ++It)
        out[--count[*It - min_e]] = *It;

    std::ranges::move(out, c.begin());
}

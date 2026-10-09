#pragma once
#include <ranges>
#include <concepts>

/*template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <typename Container>
concept NumRandomAcc = Number<std::ranges::range_value_t<Container>> &&
    std::ranges::random_access_range<Container>;
*/

template <NumRandomAcc Container>
void selection_sort(Container& c) {
    const auto n {std::ranges::size(c)};

    for(auto i {0uz}; i + 1 < n; ++i) {
        auto min_idx {i};
        for(auto j {i + 1}; j < n; ++j) {
            if(c[j] < c[min_idx])
                min_idx = j;
        }
        std::swap(c[i], c[min_idx]);
    }
}

#pragma once
#include <concepts>
#include <ranges>

/*template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <typename Container>
concept NumRandomAcc = std::ranges::random_access_range<Container> &&
    Number<std::ranges::range_value_t<Container>>;
*/

template <NumRandomAcc Container>
void insertion_sort(Container& c) {
    const auto n = std::ranges::size(c);

    for(auto i {1}; i < n; ++i) {
        auto key = c[i];
        auto j {i - 1};

        while(j >= 0 && key < c[j]) {
            c[j + 1] = c[j];
            --j;
        }

        c[j + 1] = key;
    }
}

#pragma once
#include <concepts>
#include <print>
#include <ranges>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<typename Container>
concept  NumRandomAcc = Number<std::ranges::range_value_t<Container>> &&
    std::ranges::random_access_range<Container>;

template <NumRandomAcc Container>
void bubble_sort (Container& c) {
    const auto n {std::ranges::size(c)};

    for(auto i {0uz}; i + 1 < n; ++i) {
        bool sw {false};
        for(auto j {0uz}; j < n - i - 1; ++j) {
            if(c[j] > c[j + 1]) {
                std::swap(c[j], c[j + 1]);
                sw = true;
            }
        }
        if(!sw) break;
    }
}

template <NumRandomAcc Container>
void print(const Container& c) {
    for(const auto& x : c) {
        if constexpr (std::floating_point<std::remove_cvref_t<decltype(x)>>)
            std::print("{:.2f} ", x);
        else
            std::print("{} ", x);
    }
    std::println();
}

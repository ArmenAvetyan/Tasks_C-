#pragma once
#include <concepts>
#include <ranges>

template <typename It, typename T>
concept UBCompatible = std::random_access_iterator<It> &&
    requires (std::iter_value_t<It> a, T b) {
        {a < b} -> std::convertible_to<bool>;
        {b < a} -> std::convertible_to<bool>;
    };

template <typename It, typename T>
    requires UBCompatible<It, T>
It my_upper_bound(It first, It last, const T& value) {
    while(first < last) {
        It mid {first + (last - first) / 2};

        if(*mid <= value)
            first = mid + 1;
        else
            last = mid;
    }
    return first;
}

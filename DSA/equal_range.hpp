#pragma once
#include "upper_bound.hpp"
#include "lower_bound.hpp"
#include <concepts>
#include <ranges>

template <typename It, typename T>
concept ERCompatible = std::random_access_iterator<It> &&
    requires (std::iter_value_t<It> a, T b) {
        {a < b} -> std::convertible_to<bool>;
        {b < a} -> std::convertible_to<bool>;
    };

template <typename It, typename T>
    requires ERCompatible<It, T>
std::pair<It, It> my_equal_range(It first, It last, const T& value) {
    return {my_lower_bound(first, last, value),
        my_upper_bound(first, last, value)};
}

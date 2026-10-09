#pragma once
#include <concepts>
#include <ranges>

template <typename It, typename T>
concept BSCompatible = std::random_access_iterator<It> &&
    requires (std::iter_value_t<It> a, T b) {
        {a < b} -> std::convertible_to<bool>;
        {b < a} -> std::convertible_to<bool>;
    };

template <typename It, typename T>
    requires BSCompatible<It, T>
bool my_binary_search(It first, It last, const T& value) {
    while(first < last) {
        It mid = first + (last - first) / 2;

        if(*mid < value)
            first = mid + 1;
        else if(value < *mid)
            last = mid;
        else
            return true; 
    }
    return false;
}

template <typename It, typename T>
    requires BSCompatible<It, T>
bool rec_binary_search(It first, It last, const T& value) {
    if(first >= last) return false;

    It mid = first + (last - first) / 2;

    if(*mid < value)
        return rec_binary_search(mid + 1, last, value);

    if(value < *mid)
        return rec_binary_search(first, mid, value);

    return true;
}

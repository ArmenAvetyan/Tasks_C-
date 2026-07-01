#pragma once
#include <concepts>
#include <iterator>
#include <vector>

template <typename It>
concept MSCompatible = std::random_access_iterator<It> &&
    requires (const std::iter_value_t<It>& a,
            const std::iter_value_t<It>& b) {
        {a < b} -> std::convertible_to<bool>;
    };

template <MSCompatible It>
void my_merge_sort(It first, It last) {
    auto n {std::distance(first, last)};

    if (n <= 1) return;

    It mid {std::next(first, n /2)};

    my_merge_sort(first, mid);
    my_merge_sort(mid, last);

    using T = std::iter_value_t<It>;

    std::vector<T> temp;
    temp.reserve(n);

    It left = first;
    It right = mid;

    while(left != mid && right != last) {
        if(*left < *right)
            temp.push_back(*left++);
        else
            temp.push_back(*right++);
    }

    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, last);

    std::move(temp.begin(), temp.end(), first);
}

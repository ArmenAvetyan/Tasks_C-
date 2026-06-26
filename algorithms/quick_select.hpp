#pragma once
#include <concepts>
#include <cstddef>

/*template <typename It>
    concept QSCompatible = std::random_access_iterator<It> &&
        requires (const std::iter_value_t<It>& a,
                const std::iter_value_t<It>& b) {
            {a < b} -> std::convertible_to<bool>;
        };
*/

template <QSCompatible It>
It quick_select (It first, It last, size_t n) {
    if(first == last)
        return last;

    auto p {partition(first, last)};
    auto idx {static_cast<size_t>(p - first)};

    if(idx == n) return p;
    if(n < idx) return quick_select(first, p, n);

    return quick_select(p + 1, last, n - idx - 1);
}

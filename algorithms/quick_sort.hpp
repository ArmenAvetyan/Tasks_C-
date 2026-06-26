#pragma once
#include <concepts>
#include <algorithm>

template <typename It>
    concept QSCompatible = std::random_access_iterator<It> &&
        requires (const std::iter_value_t<It>& a,
                const std::iter_value_t<It>& b) {
            {a < b} -> std::convertible_to<bool>;
        };

template <QSCompatible It>
It partition (It first, It last) {
    auto pivot {*(last - 1)};
    It i {first};

    for (It j {first}; j != last - 1; ++j) {
        if(*j <= pivot)
            std::iter_swap(i++, j);
    }

    std::iter_swap(last - 1, i);
    return i;
}

template <QSCompatible It>
void my_quick_sort(It first, It last) {
    if(first >= last || std::distance(first, last) <= 1)
        return;

    It p {partition(first, last)};

    my_quick_sort(first, p);
    my_quick_sort(p + 1, last);
}

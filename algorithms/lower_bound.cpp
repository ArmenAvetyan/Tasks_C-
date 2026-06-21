#include <concepts>
#include <ranges>
#include <vector>
#include <iostream>

template <typename It, typename T>
concept BSCompatible = std::random_access_iterator<It> &&
    requires (std::iter_value_t<It> a, T b) {
        {a < b} -> std::convertible_to<bool>;
        {b < a} -> std::convertible_to<bool>;
    };

template <typename It, typename T>
    requires BSCompatible<It, T>
It my_lower_bound(It first, It last, const T& value) {
    while (first < last) {
        It mid {first + (last - first) / 2};

        if(*mid < value)
            first = mid + 1;
        else 
            last = mid;
    }
    return first;
}

int main () {
    std::vector<int> vec {1, 2, 3, 4, 6, 7, 8, 9};
    auto Iter = my_lower_bound(vec.begin(), vec.end(), 5);

    std::cout << *Iter << '\n';
    std::cout << Iter - vec.begin() << '\n';

    vec.insert(Iter, {5,5,5,5,5});

    Iter = my_lower_bound(vec.begin(), vec.end(), 5);

    std::cout << *Iter << '\n';
    std::cout << Iter - vec.begin() << '\n';

    return 0;
}

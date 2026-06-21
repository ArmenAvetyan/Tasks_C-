#include <iostream>
#include <concepts>
#include <ranges>
#include <vector>

template <typename It, typename T>
concept BSCompatible = std::random_access_iterator<It> &&
    requires (std::iter_value_t<It> a, T b) {
        {a < b} -> std::convertible_to<bool>;
        {b < a} -> std::convertible_to<bool>;
    };

template <typename It, typename T>
    requires BSCompatible<It, T>
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

int main () {
    std::vector<int> vec {1,2,3,4,5,6,8,9};
    auto Iter = my_upper_bound(vec.begin(), vec.end(), 7);

    std::cout << *Iter << '\n';
    std::cout << Iter - vec.begin() << '\n';

    vec.insert(Iter, {7, 7, 7});
    Iter = my_upper_bound(vec.begin(), vec.end(), 7);

    std::cout << *Iter << '\n';
    std::cout << Iter - vec.begin() << '\n';

    return 0;
}

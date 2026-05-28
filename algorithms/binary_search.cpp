#include <concepts>
#include <ranges>
#include <vector>
#include <iostream>
#include <numeric>

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

int main () {
       // 1. Empty range
    {
        std::vector<int> v;
        std::cout << my_binary_search(v.begin(), v.end(), 10) << " (empty)\n";
    }

    // 2. Single element found
    {
        std::vector<int> v = {5};
        std::cout << my_binary_search(v.begin(), v.end(), 5) << " (single found)\n";
    }

    // 3. Single element not found
    {
        std::vector<int> v = {5};
        std::cout << my_binary_search(v.begin(), v.end(), 10) << " (single not found)\n";
    }

    // 4. First element
    {
        std::vector<int> v = {1,2,3,4,5};
        std::cout << my_binary_search(v.begin(), v.end(), 1) << " (first)\n";
    }

    // 5. Last element
    {
        std::vector<int> v = {1,2,3,4,5};
        std::cout << my_binary_search(v.begin(), v.end(), 5) << " (last)\n";
    }

    // 6. Missing middle
    {
        std::vector<int> v = {1,3,5,7,9};
        std::cout << my_binary_search(v.begin(), v.end(), 4) << " (missing middle)\n";
    }

    // 7. Duplicates
    {
        std::vector<int> v = {1,2,2,2,3};
        std::cout << my_binary_search(v.begin(), v.end(), 2) << " (duplicates)\n";
    }

    // 8. All same
    {
        std::vector<int> v = {7,7,7,7,7};
        std::cout << my_binary_search(v.begin(), v.end(), 7) << " (all same)\n";
    }

    // 9. Smaller than min
    {
        std::vector<int> v = {10,20,30};
        std::cout << my_binary_search(v.begin(), v.end(), 1) << " (smaller)\n";
    }

    // 10. Larger than max
    {
        std::vector<int> v = {10,20,30};
        std::cout << my_binary_search(v.begin(), v.end(), 100) << " (larger)\n";
    }

    // 11. Large range
    {
        std::vector<int> v(100000);
        std::iota(v.begin(), v.end(), 0);
        std::cout << my_binary_search(v.begin(), v.end(), 99999) << " (large)\n";
    }

    // 12. UNSORTED (undefined behavior test)
    {
        std::vector<int> v = {3,1,4,2,5,9};
        std::cout << my_binary_search(v.begin(), v.end(), 4) << " (unsorted - invalid input)\n";
    } 

    return 0;
}

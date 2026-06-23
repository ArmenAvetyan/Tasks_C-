#include "equal_range.hpp"
#include "upper_bound.hpp"
#include "lower_bound.hpp"
#include "marge_sort.hpp"
#include <cassert>
#include <random>
#include <vector>
#include <algorithm>

void test_my_equal_range() {
    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        auto expected = std::equal_range(v.begin(), v.end(), 2);
        auto actual   = my_equal_range(v.begin(), v.end(), 2);

        assert(expected.first == actual.first);
        assert(expected.second == actual.second);
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        auto expected = std::equal_range(v.begin(), v.end(), 1);
        auto actual   = my_equal_range(v.begin(), v.end(), 1);

        assert(expected.first == actual.first);
        assert(expected.second == actual.second);
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        auto expected = std::equal_range(v.begin(), v.end(), 5);
        auto actual   = my_equal_range(v.begin(), v.end(), 5);

        assert(expected.first == actual.first);
        assert(expected.second == actual.second);
    }

    {
        std::vector<int> v{1, 1, 1, 1};

        auto expected = std::equal_range(v.begin(), v.end(), 1);
        auto actual   = my_equal_range(v.begin(), v.end(), 1);

        assert(expected.first == actual.first);
        assert(expected.second == actual.second);
    }

    {
        std::vector<int> v{};

        auto expected = std::equal_range(v.begin(), v.end(), 42);
        auto actual   = my_equal_range(v.begin(), v.end(), 42);

        assert(expected.first == actual.first);
        assert(expected.second == actual.second);
    }
}

void test_my_lower_bound() {
    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_lower_bound(v.begin(), v.end(), 2) ==
               std::lower_bound(v.begin(), v.end(), 2));
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_lower_bound(v.begin(), v.end(), 1) ==
               std::lower_bound(v.begin(), v.end(), 1));
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_lower_bound(v.begin(), v.end(), 5) ==
               std::lower_bound(v.begin(), v.end(), 5));
    }

    {
        std::vector<int> v{};

        assert(my_lower_bound(v.begin(), v.end(), 42) ==
               std::lower_bound(v.begin(), v.end(), 42));
    }

    {
        std::vector<int> v{1, 1, 1, 1};

        assert(my_lower_bound(v.begin(), v.end(), 1) ==
               std::lower_bound(v.begin(), v.end(), 1));
    }
}

void test_my_upper_bound() {
    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_upper_bound(v.begin(), v.end(), 2) ==
               std::upper_bound(v.begin(), v.end(), 2));
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_upper_bound(v.begin(), v.end(), 1) ==
               std::upper_bound(v.begin(), v.end(), 1));
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_upper_bound(v.begin(), v.end(), 5) ==
               std::upper_bound(v.begin(), v.end(), 5));
    }

    {
        std::vector<int> v{};

        assert(my_upper_bound(v.begin(), v.end(), 42) ==
               std::upper_bound(v.begin(), v.end(), 42));
    }

    {
        std::vector<int> v{1, 1, 1, 1};

        assert(my_upper_bound(v.begin(), v.end(), 1) ==
               std::upper_bound(v.begin(), v.end(), 1));
    }
}


void test_my_merge_sort()
{
    {
        std::vector<int> v{};
        my_merge_sort(v.begin(), v.end());
        assert(v.empty());
    }

    {
        std::vector<int> v{42};
        my_merge_sort(v.begin(), v.end());
        assert((v == std::vector<int>{42}));
    }

    {
        std::vector<int> v{1, 2, 3, 4, 5};
        my_merge_sort(v.begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> v{5, 4, 3, 2, 1};
        my_merge_sort(v.begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    {
        std::vector<int> v{4, 1, 3, 1, 2, 4, 2};
        my_merge_sort(v.begin(), v.end());
        assert((v == std::vector<int>{1, 1, 2, 2, 3, 4, 4}));
    }

    {
        std::vector<int> v{-3, 5, -1, 0, -10, 8};
        my_merge_sort(v.begin(), v.end());
        assert((v == std::vector<int>{-10, -3, -1, 0, 5, 8}));
    }

    {
        std::array<int, 6> arr{9, 4, 7, 1, 3, 2};
        my_merge_sort(arr.begin(), arr.end());
        assert((arr == std::array<int, 6>{1, 2, 3, 4, 7, 9}));
    }

    {
        std::vector<std::string> v{
            "pear",
            "apple",
            "orange",
            "banana"
        };

        my_merge_sort(v.begin(), v.end());

        assert((v == std::vector<std::string>{
            "apple",
            "banana",
            "orange",
            "pear"
        }));
    }

    // Random stress test
    {
        std::mt19937 gen(42);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto expected = v;

            my_merge_sort(v.begin(), v.end());
            std::sort(expected.begin(), expected.end());

            assert(v == expected);
        }
    }
}

int main () {
    test_my_equal_range();
    test_my_lower_bound();
    test_my_upper_bound();
    test_my_merge_sort();

    return 0;
}

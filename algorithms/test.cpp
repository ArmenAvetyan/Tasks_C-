#include "equal_range.hpp"
#include "upper_bound.hpp"
#include "lower_bound.hpp"
#include "marge_sort.hpp"
#include "quick_sort.hpp"
#include "binary_search.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "quick_select.hpp"
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

void test_my_quick_sort()
{
    // empty
    {
        std::vector<int> v;
        my_quick_sort(v.begin(), v.end());
        assert(v.empty());
    }

    // single element
    {
        std::vector<int> v{42};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<int>{42}));
    }

    // already sorted
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // reverse sorted
    {
        std::vector<int> v{5, 4, 3, 2, 1};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // duplicates
    {
        std::vector<int> v{3, 1, 2, 3, 3, 0, 2};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<int>{0, 1, 2, 2, 3, 3, 3}));
    }

    // negative numbers
    {
        std::vector<int> v{-5, 3, -1, 0, -10, 8};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<int>{-10, -5, -1, 0, 3, 8}));
    }

    // array test
    {
        std::array<int, 6> arr{9, 4, 7, 1, 3, 2};
        my_quick_sort(arr.begin(), arr.end());
        assert((arr == std::array<int, 6>{1, 2, 3, 4, 7, 9}));
    }

    // strings
    {
        std::vector<std::string> v{"pear", "apple", "orange", "banana"};
        my_quick_sort(v.begin(), v.end());
        assert((v == std::vector<std::string>{"apple", "banana", "orange", "pear"}));
    }

    // random stress test
    {
        std::mt19937 gen(123);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto expected = v;

            my_quick_sort(v.begin(), v.end());
            std::sort(expected.begin(), expected.end());

            assert(v == expected);
        }
    }
}


void test_my_binary_search()
{
    {
        std::vector<int> v;
        assert(!my_binary_search(v.begin(), v.end(), 10));
    }

    {
        std::vector<int> v{5};
        assert(my_binary_search(v.begin(), v.end(), 5));
        assert(!my_binary_search(v.begin(), v.end(), 3));
    }

    {
        std::vector<int> v{1, 3, 5, 7, 9};

        assert(my_binary_search(v.begin(), v.end(), 1));
        assert(my_binary_search(v.begin(), v.end(), 5));
        assert(my_binary_search(v.begin(), v.end(), 9));

        assert(!my_binary_search(v.begin(), v.end(), 0));
        assert(!my_binary_search(v.begin(), v.end(), 4));
        assert(!my_binary_search(v.begin(), v.end(), 10));
    }

    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(my_binary_search(v.begin(), v.end(), 2));
        assert(!my_binary_search(v.begin(), v.end(), 5));
    }

    {
        std::vector<int> v{-10, -5, -2, 0, 3, 8};

        assert(my_binary_search(v.begin(), v.end(), -10));
        assert(my_binary_search(v.begin(), v.end(), 0));
        assert(my_binary_search(v.begin(), v.end(), 8));

        assert(!my_binary_search(v.begin(), v.end(), -7));
    }

    // stress test
    {
        std::vector<int> v(100);

        for (int i = 0; i < 100; ++i)
            v[i] = i * 2;

        for (int x = -10; x < 210; ++x)
        {
            bool expected = false;

            for (int y : v)
            {
                if (y == x)
                {
                    expected = true;
                    break;
                }
            }

            assert(my_binary_search(v.begin(), v.end(), x) == expected);
        }
    }
}

void test_rec_binary_search()
{
    // empty
    {
        std::vector<int> v;
        assert(!rec_binary_search(v.begin(), v.end(), 10));
    }

    // single element
    {
        std::vector<int> v{5};

        assert(rec_binary_search(v.begin(), v.end(), 5));
        assert(!rec_binary_search(v.begin(), v.end(), 3));
    }

    // two elements
    {
        std::vector<int> v{1, 3};

        assert(rec_binary_search(v.begin(), v.end(), 1));
        assert(rec_binary_search(v.begin(), v.end(), 3));
        assert(!rec_binary_search(v.begin(), v.end(), 2));
    }

    // odd size
    {
        std::vector<int> v{1, 3, 5, 7, 9};

        assert(rec_binary_search(v.begin(), v.end(), 1));
        assert(rec_binary_search(v.begin(), v.end(), 5));
        assert(rec_binary_search(v.begin(), v.end(), 9));

        assert(!rec_binary_search(v.begin(), v.end(), 0));
        assert(!rec_binary_search(v.begin(), v.end(), 4));
        assert(!rec_binary_search(v.begin(), v.end(), 10));
    }

    // even size
    {
        std::vector<int> v{2, 4, 6, 8, 10, 12};

        assert(rec_binary_search(v.begin(), v.end(), 2));
        assert(rec_binary_search(v.begin(), v.end(), 6));
        assert(rec_binary_search(v.begin(), v.end(), 12));

        assert(!rec_binary_search(v.begin(), v.end(), 1));
        assert(!rec_binary_search(v.begin(), v.end(), 7));
        assert(!rec_binary_search(v.begin(), v.end(), 13));
    }

    // duplicates
    {
        std::vector<int> v{1, 2, 2, 2, 3, 4};

        assert(rec_binary_search(v.begin(), v.end(), 2));
        assert(rec_binary_search(v.begin(), v.end(), 3));
        assert(!rec_binary_search(v.begin(), v.end(), 5));
    }

    // negatives
    {
        std::vector<int> v{-10, -5, -2, 0, 3, 8};

        assert(rec_binary_search(v.begin(), v.end(), -10));
        assert(rec_binary_search(v.begin(), v.end(), -2));
        assert(rec_binary_search(v.begin(), v.end(), 8));

        assert(!rec_binary_search(v.begin(), v.end(), -7));
        assert(!rec_binary_search(v.begin(), v.end(), 100));
    }

    // stress test
    {
        std::vector<int> v(100);

        for (int i = 0; i < 100; ++i)
            v[i] = i * 2;

        for (int x = -10; x < 210; ++x)
        {
            bool expected = false;

            for (int y : v)
            {
                if (y == x)
                {
                    expected = true;
                    break;
                }
            }

            assert(rec_binary_search(v.begin(), v.end(), x) == expected);
        }
    }
}

void test_bubble_sort()
{
    // empty
    {
        std::vector<int> v;
        bubble_sort(v);
        assert(v.empty());
    }

    // single element
    {
        std::vector<int> v{42};
        bubble_sort(v);
        assert((v == std::vector<int>{42}));
    }

    // already sorted
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        bubble_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // reverse sorted
    {
        std::vector<int> v{5, 4, 3, 2, 1};
        bubble_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // duplicates
    {
        std::vector<int> v{4, 1, 3, 1, 2, 4, 2};
        bubble_sort(v);
        assert((v == std::vector<int>{1, 1, 2, 2, 3, 4, 4}));
    }

    // negatives
    {
        std::vector<int> v{-3, 5, -1, 0, -10, 8};
        bubble_sort(v);
        assert((v == std::vector<int>{-10, -3, -1, 0, 5, 8}));
    }

    // all equal
    {
        std::vector<int> v{7, 7, 7, 7, 7};
        bubble_sort(v);
        assert((v == std::vector<int>{7, 7, 7, 7, 7}));
    }

    // array
    {
        std::array<int, 6> arr{9, 4, 7, 1, 3, 2};
        bubble_sort(arr);
        assert((arr == std::array<int, 6>{1, 2, 3, 4, 7, 9}));
    }

    // stress test
    {
        std::mt19937 gen(123);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto expected = v;

            bubble_sort(v);
            std::sort(expected.begin(), expected.end());

            assert(v == expected);
        }
    }
}

void test_insertion_sort()
{
    // empty
    {
        std::vector<int> v;
        insertion_sort(v);
        assert(v.empty());
    }

    // single element
    {
        std::vector<int> v{42};
        insertion_sort(v);
        assert((v == std::vector<int>{42}));
    }

    // already sorted
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        insertion_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // reverse sorted
    {
        std::vector<int> v{5, 4, 3, 2, 1};
        insertion_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // duplicates
    {
        std::vector<int> v{4, 1, 3, 1, 2, 4, 2};
        insertion_sort(v);
        assert((v == std::vector<int>{1, 1, 2, 2, 3, 4, 4}));
    }

    // negatives
    {
        std::vector<int> v{-3, 5, -1, 0, -10, 8};
        insertion_sort(v);
        assert((v == std::vector<int>{-10, -3, -1, 0, 5, 8}));
    }

    // all equal
    {
        std::vector<int> v{7, 7, 7, 7, 7};
        insertion_sort(v);
        assert((v == std::vector<int>{7, 7, 7, 7, 7}));
    }

    // array
    {
        std::array<int, 6> arr{9, 4, 7, 1, 3, 2};
        insertion_sort(arr);
        assert((arr == std::array<int, 6>{1, 2, 3, 4, 7, 9}));
    }

    // stress test
    {
        std::mt19937 gen(123);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto expected = v;

            insertion_sort(v);
            std::sort(expected.begin(), expected.end());

            assert(v == expected);
        }
    }
}

void test_selection_sort()
{
    // empty
    {
        std::vector<int> v;
        selection_sort(v);
        assert(v.empty());
    }

    // single element
    {
        std::vector<int> v{42};
        selection_sort(v);
        assert((v == std::vector<int>{42}));
    }

    // already sorted
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        selection_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // reverse sorted
    {
        std::vector<int> v{5, 4, 3, 2, 1};
        selection_sort(v);
        assert((v == std::vector<int>{1, 2, 3, 4, 5}));
    }

    // duplicates
    {
        std::vector<int> v{4, 1, 3, 1, 2, 4, 2};
        selection_sort(v);
        assert((v == std::vector<int>{1, 1, 2, 2, 3, 4, 4}));
    }

    // negatives
    {
        std::vector<int> v{-3, 5, -1, 0, -10, 8};
        selection_sort(v);
        assert((v == std::vector<int>{-10, -3, -1, 0, 5, 8}));
    }

    // all equal
    {
        std::vector<int> v{7, 7, 7, 7, 7};
        selection_sort(v);
        assert((v == std::vector<int>{7, 7, 7, 7, 7}));
    }

    // array
    {
        std::array<int, 6> arr{9, 4, 7, 1, 3, 2};
        selection_sort(arr);
        assert((arr == std::array<int, 6>{1, 2, 3, 4, 7, 9}));
    }

    // stress test
    {
        std::mt19937 gen(123);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto expected = v;

            selection_sort(v);
            std::sort(expected.begin(), expected.end());

            assert(v == expected);
        }
    }
}

void test_quick_select()
{
    // empty
    {
        std::vector<int> v;
        assert(quick_select(v.begin(), v.end(), 0) == v.end());
    }

    // single element
    {
        std::vector<int> v{5};
        auto it = quick_select(v.begin(), v.end(), 0);

        assert(it != v.end());
        assert(*it == 5);
    }

    // sorted
    {
        std::vector<int> v{1, 2, 3, 4, 5};

        for (std::size_t k = 0; k < v.size(); ++k)
        {
            auto copy = v;
            auto it = quick_select(copy.begin(), copy.end(), k);

            assert(it != copy.end());
            assert(*it == static_cast<int>(k + 1));
        }
    }

    // reverse
    {
        std::vector<int> v{5, 4, 3, 2, 1};

        for (std::size_t k = 0; k < v.size(); ++k)
        {
            auto copy = v;
            auto it = quick_select(copy.begin(), copy.end(), k);

            assert(it != copy.end());
            assert(*it == static_cast<int>(k + 1));
        }
    }

    // duplicates
    {
        std::vector<int> v{4, 1, 2, 2, 5, 3, 2};

        auto sorted = v;
        std::sort(sorted.begin(), sorted.end());

        for (std::size_t k = 0; k < v.size(); ++k)
        {
            auto copy = v;
            auto it = quick_select(copy.begin(), copy.end(), k);

            assert(it != copy.end());
            assert(*it == sorted[k]);
        }
    }

    // random stress
    {
        std::mt19937 gen(123);
        std::uniform_int_distribution<int> dist(-1000, 1000);

        for (int t = 0; t < 1000; ++t)
        {
            std::vector<int> v(100);

            for (auto& x : v)
                x = dist(gen);

            auto sorted = v;
            std::sort(sorted.begin(), sorted.end());

            for (std::size_t k = 0; k < v.size(); ++k)
            {
                auto copy = v;
                auto it = quick_select(copy.begin(), copy.end(), k);

                assert(it != copy.end());
                assert(*it == sorted[k]);
            }
        }
    }
}

int main () {
    test_my_equal_range();
    test_my_lower_bound();
    test_my_upper_bound();
    test_my_merge_sort();
    test_my_quick_sort();
    test_my_binary_search();
    test_rec_binary_search();
    test_bubble_sort();
    test_insertion_sort();
    test_selection_sort();
    test_quick_select();

    return 0;
}

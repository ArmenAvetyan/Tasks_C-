#include "equal_range.hpp"
#include "upper_bound.hpp"
#include "lower_bound.hpp"
#include <cassert>
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

int main () {
    test_my_equal_range();
    test_my_lower_bound();
    test_my_upper_bound();

    return 0;
}

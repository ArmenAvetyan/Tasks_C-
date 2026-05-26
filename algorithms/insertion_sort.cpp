#include <concepts>
#include <ranges>
#include <print>
#include <vector>
#include <array>

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <typename Container>
concept NumRandomAcc = std::ranges::random_access_range<Container> &&
    Number<std::ranges::range_value_t<Container>>;

template <NumRandomAcc Container>
void insertion_sort(Container& c) {
    const auto n = std::ranges::size(c);

    for(auto i {1}; i < n; ++i) {
        auto key = c[i];
        auto j {i - 1};

        while(j >= 0 && key < c[j]) {
            c[j + 1] = c[j];
            --j;
        }

        c[j + 1] = key;
    }
}

template <NumRandomAcc Container>
void print(const Container& c) {
    for(const auto& x : c) {
        if constexpr (std::floating_point<std::remove_cvref_t<decltype(x)>>)
            std::print("{:.2f} ", x);
        else
            std::print("{} ", x);
    }
    std::println();
}

int main () {
    std::vector v {1, 5, 6, 8, 9, 2, 4};
    std::array<float, 7> a {1.2, 5.3, 6.4, 8.5, 9.6, 2.4, 4.2};
    int arr[] {1, 5, 6, 8, 9, 2, 4};

    print(v);
    insertion_sort(v);

    std::print("Sorted array: ");
    print(v);
    std::println("\n");

//___________________________________________________________________

    print(a);
    insertion_sort(a);

    std::print("Sorted array: ");
    print(a);
    std::println("\n");

//___________________________________________________________________

    print(arr);
    insertion_sort(arr);

    std::print("Sorted array: ");
    print(arr);
    std::println("\n");

    return 0;
}

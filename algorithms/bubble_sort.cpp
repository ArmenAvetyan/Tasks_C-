#include <concepts>
#include <span>
#include <print>
#include <vector>
#include <array>
#include <ranges>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<typename Container>
concept  NumRandomAcc = Number<std::ranges::range_value_t<Container>> &&
    std::ranges::random_access_range<Container>;

template <NumRandomAcc Container>
void bubble_sort (Container& c) {
    const auto n {std::ranges::size(c)};

    for(auto i {0uz}; i < n - 1; ++i) {
        bool sw {false};
        for(auto j {0uz}; j < n - i - 1; ++j) {
            if(c[j] > c[j + 1]) {
                std::swap(c[j], c[j + 1]);
                sw = true;
            }
        }
        if(!sw) break;
    }
}

template <NumRandomAcc Container>
void print(const Container& c) {
    for(const auto& x : c)
        if constexpr (std::floating_point<std::remove_cvref_t<decltype(x)>>)
            std::print("{:.2f} ", x);
        else
            std::print("{} ", x);
    std::println();
}

int main () {
    std::vector v {1, 5, 6, 8, 9, 2, 4};
    std::array<float, 7> a {1.2, 5.3, 6.4, 8.5, 9.6, 2.4, 4.2};
    int arr[] {1, 5, 6, 8, 9, 2, 4};

    print(v);
    bubble_sort(v);

    std::print("Sorted array: ");
    print(v);
    std::println("\n");

//___________________________________________________________________

    print(a);
    bubble_sort(a);

    std::print("Sorted array: ");
    print(a);
    std::println("\n");

//___________________________________________________________________

    print(arr);
    bubble_sort(arr);

    std::print("Sorted array: ");
    print(arr);
    std::println("\n");

    return 0;
}

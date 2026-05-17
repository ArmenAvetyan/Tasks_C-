#include <iostream>
#include <tuple>
#include <utility>
#include <cstddef>

template <typename Tuple, size_t... Is>
void pr_rev_imp(const Tuple& t, std::index_sequence<Is...>) {
    ((std::cout << std::get<sizeof...(Is) - 1 - Is>(t) << ' '), ...);
}

template <typename... Args>
void print_reverse(Args&&... args) {
    auto t = std::forward_as_tuple(args...);

    pr_rev_imp(t, std::make_index_sequence<sizeof...(Args)> {});

    std::cout << '\n';
}

int main () {

    print_reverse(1, 2, 3, "hello", 4, 5);

    return 0;
}

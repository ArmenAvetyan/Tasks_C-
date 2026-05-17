#include <algorithm>
#include <iostream>
#include <print>

template <typename T, typename... Args>
T max_variadic(T first, Args... args){
    ((first = std::max(first, args)), ...);
    return first;
}

int main () {
    
    std::println("{} ", max_variadic(1, 5, 3, 6, 7, 8, 1, 3, 4, 5));

    return 0;
}

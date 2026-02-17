#include <iostream>
#include <format>

int main () {
    int x {23};

    std::cout << std::format("Test for C++{} version\n", x);

    return 0;
}

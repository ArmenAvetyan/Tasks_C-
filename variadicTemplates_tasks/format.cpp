#include <iostream>
#include <format>
#include <string>

template <typename... Args>
std::string format(std::format_string<Args...> fmt, Args&&... args) {
    return std::format(fmt, std::forward<Args>(args)...);
}

int main () {

    std::cout << format("Hello {}, age {}", "Armen", 21) << '\n';

    return 0;
}

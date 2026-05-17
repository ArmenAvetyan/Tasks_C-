#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

template <typename T, typename... Args>
void print_with_separator(const char* sep, T&& first, Args&&... args) {
    std::cout << std::forward<T>(first);

    ((std::cout << sep << std::forward<Args>(args)), ...);

    std::cout << "\n";
}

std::string uppercase(std::string s){
    std::transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){
        return std::toupper(c);
    });

    return s;
}

template <typename... Args>
void print_upper(Args&&... args) {

    ((std::cout << uppercase(args)), ...);

    std::cout << "\n";
}

std::string remove_spaces(std::string s){
    s.erase(std::remove_if(s.begin(), s.end(),
        [](unsigned char c){
            return std::isspace(c);
        }),
        s.end());
    return s;
}

template <typename... Args>
void print_compressed(Args&&... args) {
    ((std::cout << remove_spaces(args)), ...);

    std::cout << "\n";
}

int main() {
    print_with_separator(", ", "armen", "artur", "ani");

    print_upper("armen ", "artur ", "ani");

    print_compressed("  this   is    compressed  ");

    return 0;
}

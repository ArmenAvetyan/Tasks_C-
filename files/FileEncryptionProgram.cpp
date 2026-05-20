#include <iostream>
#include <fstream>
#include <print>
#include <string>

int main () {
    std::string src {};
    std::string dest {};

    std::print("Enter source filename: ");
    std::cin >> src;
    std::print("Enter destination filename: ");
    std::cin >> dest;

    std::ifstream in(src);

    if(!in) {
        std::println(std::cerr, "Source file does not exist!");
        return -1;
    }

    std::ofstream out(dest);
    char c {};
    while(in.get(c)) {
        out.put(c + 3);
    }

    std::println("The encrypted text is stored in {}", dest);

    return 0;
}

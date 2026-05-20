#include <iostream>
#include <fstream>
#include <print>
#include <string>

int main() {
    std::string file1 {};
    std::string file2 {};
    std::string dest {};

    std::print("Enter first filename: ");
    std::cin >> file1;

    std::print("Enter second filename: ");
    std::cin >> file2;

    std::print("Enter destination filename: ");
    std::cin >> dest;

    std::ifstream in1(file1);
    std::ifstream in2(file2);

    if (!in1) {
        std::println(std::cerr, "Cannot open {}", file1);
        return 1;
    }

    if (!in2) {
        std::println(std::cerr, "Cannot open {}", file2);
        return 1;
    }

    std::ofstream out(dest);

    if (!out) {
        std::println(std::cerr, "Cannot create {}", dest);
        return 1;
    }

    std::string line {};

    while (std::getline(in1, line)) {
        out << line << '\n';
    }

    out << "\n==========\n\n";

    while (std::getline(in2, line)) {
        out << line << '\n';
    }

    std::println("Files merged into {}", dest);

    return 0;
}

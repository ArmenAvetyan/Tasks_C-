#include <iostream>
#include <fstream>
#include <sstream>
#include <print>
#include <cstddef>

int main () {
    std::string src {};
    std::string str {};
    size_t ch {};
    size_t words {};
    size_t lines {};

    std::print("Enter source filename: ");
    std::cin >> src;

    std::ifstream in(src);

    if(!in) {
        std::println(std::cerr, "Source file does not exist!");
        return -1;
    }

    while(std::getline(in, str)) {
        ++lines;

        ch += str.length();

        std::stringstream ss (str);
        std::string word {};

        while(ss >> word)
            ++words;
    }

    in.close();

    std::println("File Statistics:");
    std::println("Number of characters: {}", ch);
    std::println("Number of words: {}", words);
    std::println("Number of lines: {}", lines);

    return 0;
}

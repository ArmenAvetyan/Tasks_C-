#include "onStore.hpp"
#include <iostream>
#include <format>

int main () {
    Product Laptop("Laptop", 1000);
    Product Headphones("Headphones", 200);

    Customer man;
    man.add_product(Laptop);
    man.add_product(Headphones);

    man.getInfo();

    std::cout << std::format("\nAfter discount:\n");
    man.discount(10);

    man.total_price();

    return 0;
}

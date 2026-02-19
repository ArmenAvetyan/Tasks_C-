#include "onStore.hpp"

#include <iostream>
#include <format>

//Product
Product::Product(const std::string name, int price) 
    : name(name), price(price) {}

void Product::getInfo() const
{
    std::cout << format("Product name: {}\nPrice: {}$\n", name, price);
}

std::string Product::getName() const
{
    return name;
}

int Product::getPrice() const
{
    return price;
}

void Product::discount(int x) 
{
    price -= price / 100 * x;
}

//Cart
void Cart::add_product(const Product& product) 
{
    products.push_back(std::move(product));
}

void Cart::remove_product(const std::string& rmname) 
{
    for (Product& x : products) {
        if (x.getName() == rmname) {
            x = products.back();
            products.pop_back();
            return;
        }
    }
}

void Cart::getInfo() const
{
    for (const Product& x : products) {
        x.getInfo();
    }
}

void Cart::total_price() const 
{
    int total {0};
    for (const Product& x : products) {
        total += x.getPrice();
    }
    std::cout << std::format("Total price: {}$\n", total);
}

void Cart::discount(int a)
{
    for (Product& x : products) {
        x.discount(a);
        x.getInfo();
    }
}

//Customer
void Customer::add_product(const Product& product)
{
    cart.add_product(product);
}

void Customer::remove_product(const std::string& name)
{
    cart.remove_product(name);
}

void Customer::discount(int percent)
{
    cart.discount(percent);
}

void Customer::getInfo() const
{
    cart.getInfo();
}

void Customer::total_price() const
{
    cart.total_price();
}

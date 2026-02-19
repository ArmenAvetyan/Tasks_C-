#ifndef ONSTORE_HPP
#define ONSTORE_HPP

#include <string>
#include <vector>

class Product
{
    private:
        std::string name;
        double price;
    
    public:
        Product(const std::string name, int price);

        void getInfo() const;
        std::string getName() const;
        int getPrice() const;
        void discount(int x);
};

class Cart 
{
    private:
        std::vector<Product> products;

    public:
        void add_product(const Product& product);
        void remove_product(const std::string& rmname);
        void getInfo() const;
        void discount(int a);
        void total_price() const;
};

class Customer
{
    private:
        Cart cart;

    public:
        void add_product(const Product& product);
        void remove_product(const std::string& rmname);
        void getInfo() const;
        void discount(int percent);
        void total_price() const;
};

#endif

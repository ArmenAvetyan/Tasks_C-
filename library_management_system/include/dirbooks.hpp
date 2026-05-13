#pragma once

#include <cstddef>
#include <string>
#include "book.hpp"

class PrintBook : public Book
{
    public:
        PrintBook(std::string name, std::string author, size_t count);
        ~PrintBook();
    public:
        void display() const override;
        void onBorrowed() override;
        void onReturned() override;

    private:
        size_t m_count {};
        size_t m_borrowedC {};
};

class EBook : public Book
{
    public:
        EBook(std::string name, std::string author, size_t size, std::string link = "armbook.am");
        ~EBook();
    public:
        void display() const override;
        void onBorrowed() override;
        void onReturned() override;
    private:
        std::string m_link {};
        size_t m_size {};
};

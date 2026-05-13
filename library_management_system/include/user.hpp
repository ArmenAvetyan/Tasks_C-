#pragma once
#include <string>
#include <cstddef>
#include <vector>
#include "date.hpp"
#include "book.hpp"
#include "record.hpp"

struct LoanInfo
{
    Book* book;
    Date borrowDate;
    Date dueDate;
};

class User
{
    public:
        User(std::string name, size_t maxBooks = 0, size_t maxDays = 0);
        ~User();
    public:
        std::string getName() const;
        virtual double getFineRate() const = 0;
        virtual size_t getMaxDays() const;
    public:
        void takeBook(Book& book, const Date& borrowDate, const Date& dueDate);
        void returnBook(Book& book, const Date& retDate);
        bool canTake() const;
        bool hasBook(Book* book) const;
    private:
        const std::string m_name {};
        size_t m_maxBooks {};
        size_t m_maxDays {};
        std::vector<Book*> m_takenBooks {};
        std::vector<Record> m_history {};
        std::vector<LoanInfo> m_currLoans {};
};

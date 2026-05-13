#pragma once
#include <memory>
#include <vector>
#include <string>
#include "user.hpp"
#include "book.hpp"
#include "record.hpp"

class Library
{
    public:
        Library();
        ~Library();
    public:
        void addBook(std::unique_ptr<Book> book);
        void registerUser(User* user);
        bool borrowBook(User& user, const std::string& bookTitle, Date& currentDate);
        double returnBook(User& user, const std::string& bookTitle, Date& retDate);
        Book* findBook(const std::string& title);
    private:
        double calculateFine(User& user, const Date& dueDate, const Date& retDate);
    private:
        std::vector<std::unique_ptr<Book>> m_books;
        std::vector<User*> m_users;
        std::vector<Record> m_records;
};

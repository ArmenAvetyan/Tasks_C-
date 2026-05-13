#pragma once
#include "book.hpp"
#include "date.hpp"
#include <cstddef>

class User;

class Record
{
    public:
        Record(Book* book, User* user, Date borrowDate, Date dueDate, Date retDate = Date());
        ~Record();
    public:
        void markReturned(const Date& retDate);
        size_t getDaysLate(const Date& currentDate) const;
    public:
        Book* getBook() const;
        User* getUser() const;
        Date getDueDate() const;
        Date getBorrowDate() const;
        Date getReturnDate() const;
        bool isReturned() const;

    private:
        Book* m_book {};
        User* m_user {};
        Date m_borrowDate {};
        Date m_dueDate {};
        Date m_returnDate {};
        bool m_isReturned {};
};

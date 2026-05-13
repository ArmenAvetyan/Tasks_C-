#include "record.hpp"
#include "user.hpp"

Record::Record(Book* book, User* user, Date borrowDate, Date dueDate, Date retDate)
    : m_book(book), m_user(user), m_borrowDate(borrowDate),
    m_dueDate(dueDate), m_returnDate(retDate)
{
}

Record::~Record() = default;

void Record::markReturned(const Date& retDate)
{
    m_returnDate = retDate;
    m_isReturned = true;
}

size_t Record::getDaysLate(const Date& currentDate) const
{
    if(!m_isReturned) {
        if(currentDate <= m_dueDate)
            return 0;
        return currentDate.daysBetween(m_dueDate);
    }

    if(m_returnDate <= m_dueDate)
        return 0;

    return m_returnDate.daysBetween(m_dueDate);
}

Book* Record::getBook() const
{
    return m_book;
}

User* Record::getUser() const
{
    return m_user;
}

Date Record::getDueDate() const
{
    return m_dueDate;
}

Date Record::getBorrowDate() const
{
    return m_borrowDate;
}

Date Record::getReturnDate() const
{
    return m_returnDate;
}

bool Record::isReturned() const
{
    return m_isReturned;
}

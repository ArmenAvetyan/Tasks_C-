#include "user.hpp"
#include <utility>
#include <print>
#include <algorithm>

User::User(std::string name, size_t maxBooks, size_t maxDays)
    : m_name(std::move(name)), m_maxBooks(maxBooks), m_maxDays(maxDays)
{
}

User::~User() = default;

std::string User::getName() const
{
    return m_name;
}

size_t User::getMaxDays() const
{
    return m_maxDays;
}

void User::takeBook(Book& book, const Date& borrowDate, const Date& dueDate)
{
    if(!canTake()){
        std::println("You can not take more books!");
        return;
    }

    m_takenBooks.push_back(&book);
    m_currLoans.push_back({&book, borrowDate, dueDate});
}

void User::returnBook(Book& book, const Date& retDate)
{
    auto it = std::find(m_takenBooks.begin(), m_takenBooks.end(), &book);
    if(it != m_takenBooks.end())
        m_takenBooks.erase(it);

    for(auto it = m_currLoans.begin(); it != m_currLoans.end(); ++it) {
        if(it->book == &book) {
            m_history.push_back(Record{&book, this, it->borrowDate, it->dueDate, retDate});
            m_currLoans.erase(it);
            return;
        }
    }
}

bool User::canTake() const
{
    return m_takenBooks.size() < m_maxBooks;
}

bool User::hasBook(Book* book) const
{
    if(book == nullptr)
        return false;

    return std::find(m_takenBooks.cbegin(), m_takenBooks.cend(), book)
        != m_takenBooks.cend();
}

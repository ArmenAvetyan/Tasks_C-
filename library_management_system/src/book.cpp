#include "book.hpp"
#include <utility>

Book::Book(std::string name, std::string author)
    : m_name(std::move(name)),
    m_author(std::move(author)),
    m_status(BookStatus::AVAILABLE) 
{
}

Book::~Book() = default;

void Book::setStatus(BookStatus status)
{
    m_status = status;
}

std::string Book::getName() const noexcept
{
    return m_name;
}

std::string Book::getAuthor() const noexcept
{
    return m_author;
}

bool Book::isAvailable() const noexcept
{
    return m_status == BookStatus::AVAILABLE;
}

void Book::onBorrowed()
{
    m_status = BookStatus::BORROWED;
}

void Book::onReturned()
{
    m_status = BookStatus::AVAILABLE;
}

#include "dirbooks.hpp"
#include <print>
#include <utility>

PrintBook::PrintBook(std::string name, std::string author, size_t count)
    : Book(std::move(name), std::move(author)), m_count(count)
{
}

PrintBook::~PrintBook() = default;

void PrintBook::display() const
{
    std::println("=== Print Book ===");
    std::println("Title     : {}", getName());
    std::println("Author    : {}", getAuthor());
    std::println("Copies    : {}", m_count);
    std::println("Status    : {}\n", isAvailable() ? "Available" : "Borrowed");
}

void PrintBook::onBorrowed()
{
    if(m_borrowedC < m_count)
        ++m_borrowedC;
    if(m_borrowedC >= m_count)
        setStatus(BookStatus::BORROWED);
    else
        setStatus(BookStatus::AVAILABLE);
}

void PrintBook::onReturned()
{
    if(m_borrowedC > 0)
        --m_borrowedC;
    if(m_borrowedC < m_count)
        setStatus(BookStatus::AVAILABLE);
}


EBook::EBook(std::string name, std::string author, size_t size, std::string link)
    : Book(std::move(name), std::move(author)), m_size(size), m_link(std::move(link))
{
}

EBook::~EBook() = default;

void EBook::display() const
{
    std::println("=== E-Book ===");
    std::println("Title     : {}", getName());
    std::println("Author    : {}", getAuthor());
    std::println("Size      : {} KB", m_size);
    std::println("Link      : {}", m_link);
    std::println("Status    : {}\n", isAvailable() ? "Available" : "Borrowed");
}

void EBook::onBorrowed()
{
    Book::onBorrowed();
}

void EBook::onReturned()
{
    Book::onBorrowed();
}

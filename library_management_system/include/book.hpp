#pragma once
#include <string>

enum class BookStatus
{
    AVAILABLE, BORROWED, RESERVED
};

class Book
{
    public:
        Book(std::string name, std::string author);
        virtual ~Book();
    public:
        void setStatus(BookStatus status);
        std::string getName() const noexcept;
        std::string getAuthor() const noexcept;
        bool isAvailable() const noexcept;
    public:
        virtual void display() const = 0;
    public:
        virtual void onBorrowed();
        virtual void onReturned();
        
    private:
        const std::string m_name {};
        const std::string m_author {};
        BookStatus m_status {};
};

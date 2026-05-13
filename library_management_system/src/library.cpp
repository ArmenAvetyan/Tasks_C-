#include "library.hpp"
#include <string>
#include <memory>
#include <vector>
#include <print>
#include <utility>

Library::Library() = default;

Library::~Library() = default;

void Library::addBook(std::unique_ptr<Book> book)
{
    m_books.push_back(std::move(book));
}

void Library::registerUser(User* user)
{
    m_users.push_back(user);
}

bool Library::borrowBook(User& user, const std::string& bookTitle, Date& currentDate)
{
    Book* book = findBook(bookTitle);
    if(book == nullptr) {
        std::println("Book is not found: {}", bookTitle);
        return false;
    }

    if(!book->isAvailable()) {
        std::println("Book in not available: {}",  bookTitle);
        return false;
    }

    if(!user.canTake()) {
        std::println("{} can not take books!", user.getName());
        return false;
    }

    Date dueDate = currentDate.addDays(user.getMaxDays());

    book->onBorrowed();

    user.takeBook(*book, currentDate, dueDate);

    m_records.push_back(Record(book, &user, currentDate, dueDate));

    std::println("{} took {} book", user.getName(), bookTitle);
    std::print("Due date: ");
    dueDate.displayDate();

    return true;
}

double Library::returnBook(User& user, const std::string& bookTitle, Date& retDate)
{
    Book* book = findBook(bookTitle);
    if(!book){
        std::println("{} not found!", bookTitle);
        return -1.0;
    }

    if(!user.hasBook(book)){
        std::println("{} has not book: {}", user.getName(), bookTitle);
        return -1.0;
    }

    Date dueDate {};
    for (auto& record : m_records)
    {
        if (record.getBook() == book && record.getUser() == &user && !record.isReturned())
        {
            dueDate = record.getDueDate();
            record.markReturned(retDate);
            break;
        }
    }

    double fine = calculateFine(user, dueDate, retDate);

    book->onReturned();
    user.returnBook(*book, retDate);

    if (fine > 0.0)
        std::println("The book was returned late. Fine: {:.0f}", fine);
    else
        std::println("The book was successfully returned: {}", bookTitle);

    return fine;
}

Book* Library::findBook(const std::string& title)
{
    for(const auto& bookPtr : m_books){
        if(bookPtr && bookPtr->getName() == title)
            return bookPtr.get();
    }
    return nullptr;
}

double Library::calculateFine(User& user, const Date& dueDate, const Date& retDate)
{
    if(retDate <= dueDate)
        return 0.0;

    size_t late = retDate.daysBetween(dueDate);
    double fine = late * user.getFineRate();

    return fine;
}

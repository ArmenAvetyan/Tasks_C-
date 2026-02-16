#include "lms.hpp"
#include <iostream>

//Book class
Book::Book (std::string title, std::string author, int id) 
    : title(title), author(author), id(id) 
{
    std::cout << "Constructor called\n";
}

Book::~Book () 
{
    std::cout << "Destructor called\n";
}

//geters
std::string Book::getTitle () const 
{
    return title;
}

std::string Book::getAuthor () const
{
    return author;
}

int Book::getId () const
{
    return id;
}

//seters
void Book::setTitle (const std::string &title) 
{
    this->title = title;
}

void Book::setAuthor (const std::string &author) 
{
    this->author = author;
}

void Book::setId (const int &id) 
{
    this->id = id;
}

//
//Library
Library::Library () {}
Library::~Library () {} 

void Library::addBook(const Book& book) 
{
    books.push_back(book);
}

void Library::listBooks() const 
{
    for (const Book& b : books) {
        std::cout << b.getTitle() << "\t"
        << b.getAuthor() << "\t"
        << b.getId() << std::endl;
    }
}

Book* Library::findBookByTitle(const std::string& title)
{
    for (Book& b : books) {
        if (b.getTitle() == title) {
            Book* ptr = &b;
            return ptr;
        } 
    }
    return nullptr;
}

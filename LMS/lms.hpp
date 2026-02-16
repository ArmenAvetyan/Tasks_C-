#ifndef LMS_HPP
#define LMS_HPP

#include <string>
#include <vector>

class Book {
    private:
        std::string title;
        std::string author;
        int id;

    public:
        //constructor & destructor
        Book (std::string, std::string, int);
        ~Book();

        //geters
        std::string getTitle () const;
        std::string getAuthor () const;
        int getId () const;

        //seters
        void setTitle (const std::string &title);
        void setAuthor (const std::string &author);
        void setId (const int &id);
};

class Library {
    private:
        std::vector<Book> books;

    public:
        Library();
        ~Library();

        void addBook(const Book& book);
        void listBooks() const;
        Book* findBookByTitle(const std::string& title);
};

#endif

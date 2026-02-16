#include "lms.hpp"
#include <iostream>

int main () {
    //creating
    Book book0("CPP", "Armen", 0);
    Book book1("Clean Code", "Robert Martin", 1);
    Book book2("The Pragmatic Programmer", "Andrew Hunt", 2);
    Book book3("Design Patterns", "Erich Gamma", 3);
    Book book4("Effective Modern C++", "Scott Meyers", 4);
    Book book5("C++ Primer", "Stanley Lippman", 5);
    Book book6("Introduction to Algorithms", "Thomas H. Cormen", 6);
    Book book7("Structure and Interpretation of Computer Programs", "Harold Abelson", 7);
    Book book8("Operating System Concepts", "Abraham Silberschatz", 8);
    Book book9("Computer Networks", "Andrew S. Tanenbaum", 9);
    Book book10("Artificial Intelligence: A Modern Approach", "Stuart Russell", 10);

    //adding
    Library lib;
    lib.addBook(book0);
    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.addBook(book5);
    lib.addBook(book6);
    lib.addBook(book7);
    lib.addBook(book8);
    lib.addBook(book9);
    lib.addBook(book10);

    //list
    lib.listBooks();

    //searching
    lib.findBookByTitle("Effective Modern C++");

    return 0;
}

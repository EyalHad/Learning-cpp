#ifndef BOOK_HPP  // If BOOK_HPP has not been defined yet...
#define BOOK_HPP  // ...define it now.

#include <string> // We need to include this because our method uses the std::string type.
#include "Author.hpp"
using std::string;

class Book {
    private:    // Not required. All is private by default.
    // Member variables to store the book's data
        string title;
        Author author;
        int year;
        bool is_checked_out;
    public: 
        // Constructor declaration: how to create a Book object
        Book(const string& title, const Author& author, int year);
        // Method declaration: what a Book object can do
        void print_details() const;
        void return_book();
        void check_out();
        string get_title() const;
        // This declaration for the destructor
        ~Book();
};

#endif // End of the include guard block.
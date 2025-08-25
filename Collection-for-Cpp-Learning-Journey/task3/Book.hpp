#ifndef BOOK_HPP  // If BOOK_HPP has not been defined yet...
#define BOOK_HPP  // ...define it now.

#include <string> // We need to include this because our method uses the std::string type.
using std::string;

class Book {
    private:    // Not required. All is private by default.
    // Member variables to store the book's data
        string title;
        string author;
        int year;
    public: 
        // Constructor declaration: how to create a Book object
        Book(const string& title, const string& author, int year);
        // Method declaration: what a Book object can do
        void print_details() const;


        // This declaration for the destructor
        ~Book();
};

#endif // End of the include guard block.
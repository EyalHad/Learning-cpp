#ifndef LIBRARY_HPP  // If LIBRARY_HPP has not been defined yet...
#define LIBRARY_HPP  // ...define it now.
#include "Author.hpp"
#include "Book.hpp"

#include <string> // We need to include this because our method uses the std::string type.
#include <vector>
using namespace std;

class Library  {
    private:    // Not required. All is private by default.
    // Member variables to store the book's data
        vector<Book*> catalog;

    public: 
        // Constructor declaration: how to create a Author object
        Library();
        void add_book(const std::string& title, const Author& author, int year);
        void print_catalog() const;
        Book* find_book(const std::string& title);
        void check_out_book(const std::string& title);
        void return_book(const std::string& title);
        // This declaration for the destructor
        ~Library ();
};

#endif // End of the include guard block.
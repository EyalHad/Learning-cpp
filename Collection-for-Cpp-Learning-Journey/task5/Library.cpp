#include "Library.hpp"
#include "Book.hpp"
#include "Author.hpp"
#include <iostream>
#include <string>
#include <vector>

// Constructor can be empty, as the vector initializes itself.
Library::Library() {}

// Destructor cleans up the dynamically allocated Book objects.
Library::~Library() {
    std::cout << "Library destructor called. Cleaning up all books..." << std::endl;
    // Loop through every pointer in the catalog
    for (Book* book_ptr : catalog) {
        // Delete the Book object that the pointer points to
        delete book_ptr;
    }
}

// Creates a new Book on the heap and adds its pointer to the catalog.
void Library::add_book(const std::string& title, const Author& author, int year) {
    Book* book_ptr = new Book(title, author, year);
    catalog.push_back(book_ptr);
}

// Loops through the catalog and prints details for each book.
void Library::print_catalog() const {
    std::cout << "\n--- Library Catalog ---" << std::endl;
    for (const Book* book_ptr : catalog) {
        book_ptr->print_details();
        std::cout << "-----------------------" << std::endl;
    }
}

// Searches the catalog for a book by title.
// Returns a pointer to the book if found, otherwise returns nullptr.
Book* Library::find_book(const std::string& title) {
    for (Book* book_ptr : catalog) {
        if (book_ptr->get_title() == title) {
            return book_ptr;
        }
    }
    return nullptr; // Indicates that the book was not found.
}

// Finds a book and calls its check_out method.
void Library::check_out_book(const std::string& title) {
    Book* book_to_checkout = find_book(title);
    if (book_to_checkout != nullptr) { // Always check if the book was found
        book_to_checkout->check_out();
        std::cout << "'" << title << "' has been checked out." << std::endl;
    } else {
        std::cout << "Error: Book '" << title << "' not found in library." << std::endl;
    }
}

// Finds a book and calls its return_book method.
void Library::return_book(const std::string& title) {
    Book* book_to_return = find_book(title);
    if (book_to_return != nullptr) { // Always check
        book_to_return->return_book();
        std::cout << "'" << title << "' has been returned." << std::endl;
    } else {
        std::cout << "Error: Book '" << title << "' not found in library." << std::endl;
    }
}

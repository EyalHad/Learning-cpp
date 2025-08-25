#include "Book.hpp"
#include <iostream>

// Definition of the constructor using a member initializer list
// This is the modern C++ way to initialize members.
Book::Book(const std::string& t, const std::string& a, int y)
    : title(t), author(a), year(y) {
    // The constructor's body is empty because the initializer list did all the work.
}

// Definition of the print_details method
void Book::print_details() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Published: " << year << std::endl;
}

// This definition for the destructor
Book::~Book() {
    std::cout << "Destructor called for: " << title << std::endl;
}
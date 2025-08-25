#include "Book.hpp"
#include <iostream>

// Definition of the constructor using a member initializer list
// This is the modern C++ way to initialize members.
Book::Book(const std::string& t, const Author& a, int y)
    : title(t), author(a), year(y), is_checked_out(false) {
    // The constructor's body is empty because the initializer list did all the work.
}

// Definition of the print_details method
void Book::print_details() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author.get_name() << std::endl;
    std::cout << "Published: " << year << std::endl;
    std::cout << "Checked: " << is_checked_out << std::endl;
}

void Book::return_book(){
    is_checked_out = false;
}
void Book::check_out(){
    is_checked_out = true;
}

string Book::get_title() const{
    return title;
}
// This definition for the destructor
Book::~Book() {
    std::cout << "Destructor called for: " << title << std::endl;
}
#include "Author.hpp"
#include <iostream>

// Definition of the constructor using a member initializer list
// This is the modern C++ way to initialize members.
Author::Author(const std::string& n, u_int year)
    : name(n), birth_year(year) {
    // The constructor's body is empty because the initializer list did all the work.
}

// Definition of the get_name method
string Author::get_name() const {
    return name;
}

// This definition for the destructor
Author::~Author() {
    std::cout << "Destructor called for: " << name << std::endl;
}
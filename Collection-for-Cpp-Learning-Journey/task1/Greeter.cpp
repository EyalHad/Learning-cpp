#include "Greeter.hpp"    // Include our own header file to get the class declaration.
#include <iostream>   // We need this for std::cout.

// Here is the definition of the say_hello method.
// The "Greeter::" prefix specifies that this function is part of the Greeter class.
void Greeter::say_hello(std::string user_name) {
    std::cout << "Hello, " << user_name << "!" << std::endl;
}
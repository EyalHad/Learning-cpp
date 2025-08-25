// We need <iostream> for std::cout and std::cin
#include <iostream>
// We need <string> for the std::string variable
#include <string>
// We include our own Greeter class blueprint
#include "Greeter.hpp"

int main() {
    // 1. Declare a string variable to hold the user's name.
    std::string user_name;

    // 2. Prompt the user for their name.
    std::cout << "Please enter your name: ";

    // 3. Read the entire line of input from the user.
    // We use std::getline() so it correctly handles names with spaces.
    std::getline(std::cin, user_name);

    // 4. Create an object (an instance) of our Greeter class.
    Greeter my_greeter;

    // 5. Call the say_hello method on our object, passing it the user's name.
    my_greeter.say_hello(user_name);

    // 6. Return 0 to indicate the program ran successfully.
    return 0;
}
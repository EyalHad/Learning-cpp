
#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

#include "Author.hpp"
#include "Book.hpp"
#include "Library.hpp"

// A helper function to print the menu options
void print_menu() {
    std::cout << "\n===== Library Kiosk Menu =====\n";
    std::cout << "1. List all books\n";
    std::cout << "2. Check out a book\n";
    std::cout << "3. Return a book\n";
    std::cout << "4. Exit\n";
    std::cout << "============================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    // Create the main library object.
    // Its destructor will automatically be called when main() ends.
    Library my_library;

    // --- Pre-populate the library with some data ---
    Author author1("Frank Herbert", 1920);
    Author author2("J.R.R. Tolkien", 1892);

    my_library.add_book("Dune", author1, 1965);
    my_library.add_book("Dune Messiah", author1, 1969);
    my_library.add_book("The Hobbit", author2, 1937);
    my_library.add_book("The Lord of the Rings", author2, 1954);
    // --- End of pre-population ---

    int choice = 0;
    std::string title_input;

    // Main application loop
    while (true) {
        print_menu();
        std::cin >> choice;

        // Check if the input was valid
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            continue; // Skip the rest of the loop
        }
        
        // Consume the rest of the line after reading the number
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            my_library.print_catalog();
        } else if (choice == 2) {
            std::cout << "Enter the title of the book to check out: ";
            std::getline(std::cin, title_input);
            my_library.check_out_book(title_input);
        } else if (choice == 3) {
            std::cout << "Enter the title of the book to return: ";
            std::getline(std::cin, title_input);
            my_library.return_book(title_input);
        } else if (choice == 4) {
            std::cout << "Thank you for using the Library Kiosk. Goodbye!" << std::endl;
            break; // Exit the loop
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

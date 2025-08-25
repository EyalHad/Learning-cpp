#include <iostream>
#include <string>
#include "Book.hpp"

int main() {

    // Stack allocation
    Book book("Atomic Habits", "James Clear", 2018);
    book.print_details();

    Book book1("The Midnight Library", "Matt Haig", 2020);
    book1.print_details();

    Book book2("Educated", "Tara Westover", 2018);
    book2.print_details();

    // Heap allocation
    Book* book_ptr = new Book("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 2011);
    book_ptr->print_details();
    Book* book_ptr1 = new Book("The Alchemist", "Paulo Coelho", 1988);
    book_ptr1->print_details();

    // Destructors will be called in the order they are called (Heap)
    delete book_ptr;
    delete book_ptr1;
    
    return 0;

    // Destructors will be called in the reverse order the objects were created (Stack)

}
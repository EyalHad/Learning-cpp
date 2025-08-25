#include <iostream>

// --- Implementation 1: Using Pointers ---
// This function takes pointers (memory addresses) as arguments.
// To access the values at these addresses, we must dereference them with *.
void swap_by_pointer(int* a, int* b) {
    std::cout << "--- Swapping by pointer ---\n";
    int temp = *a; // Get the value at address 'a'
    *a = *b;       // Put the value from 'b' into the address of 'a'
    *b = temp;     // Put the saved value into the address of 'b'
}

// --- Implementation 2: Using References ---
// This function takes references as arguments. A reference is an alias,
// or a nickname, for an existing variable.
// We can work with 'a' and 'b' as if they were the original variables.
void swap_by_reference(int& a, int& b) {
    std::cout << "--- Swapping by reference ---\n";
    int temp = a;
    a = b;
    b = temp;
}

// --- Main Function to Demonstrate Both ---
int main() {
    int x = 10;
    int y = 20;

    std::cout << "Initial values: x = " << x << ", y = " << y << std::endl;

    // To call the pointer version, we must pass the MEMORY ADDRESSES
    // of x and y using the address-of operator (&).
    swap_by_pointer(&x, &y);
    std::cout << "After pointer swap: x = " << x << ", y = " << y << std::endl;

    // To call the reference version, we pass the variables directly.
    // The compiler handles the creation of aliases for us.
    swap_by_reference(x, y);
    std::cout << "After reference swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
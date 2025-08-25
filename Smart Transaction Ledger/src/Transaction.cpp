#include "Transaction.hpp"
#include <iomanip> // For std::put_time
#include <cstring> // **FIX: Added for strlen**

Transaction::Transaction(const std::string& desc) : description(desc) {
    date = std::time(nullptr); // Set current time
}

void Transaction::print_details() const {
    // ctime returns a pointer to a statically allocated string.
    char* time_str = std::ctime(&date);
    if (time_str) {
        // Remove the default newline character that ctime adds at the end.
        // **FIX: Changed std::strlen to strlen**
        time_str[strlen(time_str) - 1] = '\0';
        std::cout << "Date: " << time_str << std::endl;
    }
    std::cout << "Description: " << description << std::endl;
}

// Global operator<< overload for any Transaction
std::ostream& operator<<(std::ostream& os, const Transaction& trx) {
    trx.print_details();
    return os;
}
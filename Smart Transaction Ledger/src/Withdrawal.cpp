#include "Withdrawal.hpp"

Withdrawal::Withdrawal(double amt, const std::string& desc)
    : Transaction(desc), amount(amt) {
    if (amt <= 0) {
        // Exception Handling
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
}

double Withdrawal::get_amount() const {
    return -amount; // Withdrawals are represented as negative values
}

void Withdrawal::print_details() const {
    Transaction::print_details(); // Call base class method
    std::cout << "Type: Withdrawal" << std::endl;
    std::cout << "Amount: $" << amount << std::endl;
}

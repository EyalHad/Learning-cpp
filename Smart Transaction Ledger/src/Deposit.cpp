#include "Deposit.hpp"

Deposit::Deposit(double amt, const std::string& desc)
    : Transaction(desc), amount(amt > 0 ? amt : 0.0) {} // Ensure amount is positive

double Deposit::get_amount() const {
    return amount;
}

void Deposit::print_details() const {
    Transaction::print_details(); // Call base class method
    std::cout << "Type: Deposit" << std::endl;
    std::cout << "Amount: $" << amount << std::endl;
}
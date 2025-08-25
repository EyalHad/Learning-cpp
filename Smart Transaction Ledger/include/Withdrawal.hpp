#pragma once
#include "Transaction.hpp"
#include <stdexcept> // For std::invalid_argument

class Withdrawal : public Transaction {
private:
    double amount;

public:
    Withdrawal(double amt, const std::string& desc);
    double get_amount() const override;
    void print_details() const override;
};


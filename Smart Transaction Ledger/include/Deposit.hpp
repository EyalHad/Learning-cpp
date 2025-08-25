#pragma once
#include "Transaction.hpp"

class Deposit : public Transaction {
private:
    double amount;

public:
    Deposit(double amt, const std::string& desc);
    double get_amount() const override;
    void print_details() const override;
};


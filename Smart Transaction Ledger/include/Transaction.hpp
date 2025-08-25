#pragma once
#include <string>
#include <iostream>
#include <ctime>

class Transaction {
protected:
    std::string description;
    time_t date; // Using time_t for simplicity

public:
    Transaction(const std::string& desc);
    virtual ~Transaction() = default;

    // Pure virtual function makes this class abstract
    virtual double get_amount() const = 0;

    // A virtual function to be overridden by derived classes for custom printing
    virtual void print_details() const;

    // Friend function to allow std::cout << transaction;
    friend std::ostream& operator<<(std::ostream& os, const Transaction& trx);
};

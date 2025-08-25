#pragma once
#include <vector>
#include <string>
#include <memory> // For std::unique_ptr
#include "Transaction.hpp"
#include "IObserver.hpp"

class Ledger {
private:
    std::vector<std::unique_ptr<Transaction>> transactions;
    std::vector<IObserver*> observers;

    // Private notify method for the Observer pattern
    void notify(const Transaction& trx);

public:
    // Observer pattern methods
    void attach(IObserver* observer);
    void detach(IObserver* observer);

    // Core logic
    void add_transaction(std::unique_ptr<Transaction> trx);
    double calculate_balance() const;
    void print_statement() const;

    // File I/O
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);
};
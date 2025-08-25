#include "Ledger.hpp"
#include "Deposit.hpp"
#include "Withdrawal.hpp"
#include <numeric>   // For std::accumulate
#include <fstream>   // For file I/O
#include <sstream>   // For std::stringstream
#include <algorithm> // **FIX: Added for std::remove**

// --- Observer Pattern ---
void Ledger::attach(IObserver* observer) {
    observers.push_back(observer);
}

void Ledger::detach(IObserver* observer) {
    // This is the erase-remove idiom. std::remove shifts the elements to be kept
    // to the beginning of the range and returns an iterator to the new end.
    // .erase() then removes the elements from the new end to the actual end.
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Ledger::notify(const Transaction& trx) {
    for (IObserver* observer : observers) {
        observer->update(trx);
    }
}

// --- Core Logic ---
void Ledger::add_transaction(std::unique_ptr<Transaction> trx) {
    // Notify observers before moving the transaction, so we have a valid object to pass.
    notify(*trx);
    transactions.push_back(std::move(trx));
}

double Ledger::calculate_balance() const {
    // STL Algorithm: std::accumulate
    double initial_sum = 0.0;
    return std::accumulate(transactions.begin(), transactions.end(), initial_sum,
        [](double sum, const std::unique_ptr<Transaction>& trx) {
            return sum + trx->get_amount();
        });
}

void Ledger::print_statement() const {
    std::cout << "\n===== OFFICIAL LEDGER STATEMENT =====\n";
    for (const auto& trx : transactions) {
        // Operator Overloading: std::cout << *trx;
        std::cout << *trx << "--------------------\n";
    }
    std::cout << "FINAL BALANCE: $" << calculate_balance() << std::endl;
    std::cout << "===================================\n";
}

// --- File I/O ---
void Ledger::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& trx : transactions) {
        // We need to know the concrete type to save it correctly
        if (dynamic_cast<Deposit*>(trx.get())) {
            file << "DEPOSIT," << trx->get_amount() << "," << "Generic Deposit Description" << std::endl;
        } else if (dynamic_cast<Withdrawal*>(trx.get())) {
            // get_amount() returns a negative number, so multiply by -1 for saving
            file << "WITHDRAWAL," << trx->get_amount() * -1 << "," << "Generic Withdrawal Description" << std::endl;
        }
    }
}

void Ledger::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading: " << filename << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type, amount_str, desc;
        
        std::getline(ss, type, ',');
        std::getline(ss, amount_str, ',');
        std::getline(ss, desc, ',');

        try {
            double amount = std::stod(amount_str);
            if (type == "DEPOSIT") {
                add_transaction(std::make_unique<Deposit>(amount, desc));
            } else if (type == "WITHDRAWAL") {
                add_transaction(std::make_unique<Withdrawal>(amount, desc));
            }
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
        }
    }
}
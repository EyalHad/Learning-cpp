#pragma once
#include "Transaction.hpp" // Forward declaration would be better, but this is simpler for now

class Transaction; // Forward declaration

class IObserver {
public:
    virtual ~IObserver() = default; // Virtual destructor for base class
    // The notification method that the Subject (Ledger) will call
    virtual void update(const Transaction& trx) = 0;
};
#pragma once
#include "IObserver.hpp"
#include <iostream>

class Auditor : public IObserver {
public:
    void update(const Transaction& trx) override {
        std::cout << "\n--- AUDIT LOG ---" << std::endl;
        std::cout << "A new transaction was processed:" << std::endl;
        trx.print_details();
        std::cout << "-----------------\n" << std::endl;
    }
};

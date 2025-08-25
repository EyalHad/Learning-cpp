#pragma once
#include "IObserver.hpp"
#include <iostream>

class EmailNotifier : public IObserver {
private:
    std::string destination_email;
public:
    // The constructor now takes the specific detail it needs.
    EmailNotifier(const std::string& email) : destination_email(email) {}

    void update(const Transaction& trx) override {
        // Now it can use its specific data.
        std::cout << "Notifying Email Address " << destination_email << " about transaction." << std::endl;
        // ... logic to format and send the email ...
    }
};
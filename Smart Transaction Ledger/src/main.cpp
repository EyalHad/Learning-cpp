#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include "Ledger.hpp"
#include "Deposit.hpp"
#include "Withdrawal.hpp"
#include "Auditor.hpp"
#include "SmsNotifier.hpp"
#include "EmailNotifier.hpp"

void print_menu() {
    std::cout << "\n===== Smart Ledger Menu =====\n";
    std::cout << "1. Add Deposit\n";
    std::cout << "2. Add Withdrawal\n";
    std::cout << "3. Print Statement\n";
    std::cout << "4. Save to File\n";
    std::cout << "5. Load from File\n";
    std::cout << "6. Exit\n";
    std::cout << "============================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Ledger my_ledger;
    Auditor my_auditor;
    my_ledger.attach(&my_auditor);
    SmsNotifier sms("123456-999");;
    my_ledger.attach(&sms);
    EmailNotifier email_alert("admin@email.com");;
    my_ledger.attach(&email_alert);

    int choice = 0;
    while (true) {
        print_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume newline

        double amount;
        std::string desc;

        try {
            if (choice == 1) {
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                std::cout << "Enter description: ";
                std::cin.ignore();
                std::getline(std::cin, desc);
                my_ledger.add_transaction(std::make_unique<Deposit>(amount, desc));
            } else if (choice == 2) {
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                std::cout << "Enter description: ";
                std::cin.ignore();
                std::getline(std::cin, desc);
                my_ledger.add_transaction(std::make_unique<Withdrawal>(amount, desc));
            } else if (choice == 3) {
                my_ledger.print_statement();
            } else if (choice == 4) {
                my_ledger.save_to_file("ledger.csv");
                std::cout << "Ledger saved to ledger.csv" << std::endl;
            } else if (choice == 5) {
                my_ledger.load_from_file("ledger.csv");
                std::cout << "Ledger loaded from ledger.csv" << std::endl;
            } else if (choice == 6) {
                std::cout << "Exiting. Final balance: $" << my_ledger.calculate_balance() << std::endl;
                break;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }

    return 0;
}

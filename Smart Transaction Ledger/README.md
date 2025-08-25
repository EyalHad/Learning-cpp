# The Smart Transaction Ledger: A Capstone C++ Project

#### Overview

This project is a comprehensive "capstone" task designed to synthesize foundational and advanced C++ concepts into a single, robust application. You will build a smart, interactive, and persistent command-line accounting ledger.

The application will allow a user to record deposits and withdrawals, calculate the current balance, handle errors gracefully, and save/load the transaction history to a file. The core design will be built around modern C++ practices, including SOLID principles, smart memory management, and the Observer design pattern to create a decoupled and extendable system.
Core Concepts & Skills Gained

This project is designed to provide hands-on experience with a wide range of critical C++ topics.
1. Advanced Object-Oriented Programming (OOP)

    Polymorphism & Inheritance: You will create an abstract base Transaction class and have concrete Deposit and Withdrawal classes inherit from it. The Ledger will manage these different objects seamlessly through a single interface.

    Abstraction: The design separates the high-level logic of the Ledger from the low-level details of specific transaction types.

2. Software Design Patterns

    Observer Pattern: You will implement this classic behavioral pattern to create a decoupled notification system. The Ledger (the Subject) will notify interested components, like an Auditor (the Observer), whenever a new transaction is added, without being directly tied to them.

3. Modern C++ Features

    Smart Pointers `(std::unique_ptr)`: You will use std::unique_ptr to manage the memory of polymorphic Transaction objects. This is the modern, safe approach to RAII, preventing memory leaks automatically.

    STL Containers `(std::vector)`: The core data structure for managing the collection of transactions and observers.

    STL Algorithms `(std::accumulate)`: You will use standard library algorithms for efficient and expressive data processing, such as summing up the ledger balance in a single line.

4. Robust Programming Techniques

    Exception Handling (try...catch): You will implement robust error handling by throwing exceptions for invalid data (e.g., a negative withdrawal) and catching them to prevent the application from crashing.

    Operator Overloading `(operator<<)`: You will overload the stream insertion operator to provide a clean, intuitive way to print transaction details `(std::cout << my_transaction;)`.

    File I/O `(<fstream>)`: You will make the application's data persistent by implementing functionality to save the transaction log to a file and load it back on startup.

The Assignment: Building the Ledger

You will build the application by creating the following components:
1. The Observer Interface (IObserver)

    An abstract class with a single pure virtual function: `virtual void update(const Transaction& trx) = 0;`.

2. The Transaction Hierarchy

    Transaction (Abstract Base Class):

        Members: `date`, `description`.

        Pure Virtual Method: `virtual double get_amount() const = 0;`.

        Virtual Method: `virtual void print_details() const;`.

    Deposit & Withdrawal (Derived Classes):

        Inherit from Transaction.

        Implement `get_amount()`. A Withdrawal's amount should be negative.

        The Withdrawal constructor must throw an `std::invalid_argument` if the input amount is not positive.

3. The Auditor (IObserver Implementation)

    A concrete class that inherits from IObserver.

    Its update method will simply print a log to the console, e.g., `"AUDIT LOG: A new transaction was added: [Transaction Details]"`.

4. The Ledger (The Subject)

    Manages a `std::vector<std::unique_ptr<Transaction>>` for transactions and a `std::vector<IObserver*>` for observers.

    Subject Methods: `attach(IObserver*)`, `detach(IObserver*)`, and a `private notify(const Transaction& trx)`.

    Core Logic Methods:

        `add_transaction(...)`: Adds a transaction and calls `notify()`.

        `calculate_balance() const`: Uses std::accumulate.

        `print_statement() const`.

        `save_to_file(...) const` and `load_from_file(...)`.

5. main.cpp

    The application's entry point.

    Instantiates the Ledger and the Auditor.

    Attaches the Auditor to the Ledger.

    Contains the main application loop, handling user input within a try...catch block.

How to Compile & Run

You will need a Makefile to compile all the source files (.cpp) into object files (.o) and then link them into a single executable.

Example Makefile:
```

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = ledger_app
SRCS = main.cpp Ledger.cpp Transaction.cpp Deposit.cpp Withdrawal.cpp Auditor.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

```  

>To Run:

    make

    ./ledger_app
  
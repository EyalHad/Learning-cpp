# Collection for C++ Learning Journey

This document contains a README.md summary for each of the C++ tasks completed, from foundational concepts to advanced design patterns.
### Task 1: Command-Line Greeting Utility
Objective

To understand the fundamental structure of a multi-file C++ project by creating a simple command-line tool that greets a user by name.
Core Concepts & Skills Gained

    Project Structure: Separating class declarations into header files (.hpp) and their definitions into source files (.cpp).

    Header Guards: Using #pragma once or #ifndef/#define to prevent multiple inclusions.

    Basic I/O: Using std::cout for output and std::cin / std::getline for input from the <iostream> library.

    Standard Library Types: Using std::string for text manipulation.

    Class Basics: Declaring a class, defining its methods, and creating an instance (object).

How to Compile & Run

>Compile all source files and link them into an executable

```  
g++ main.cpp Greeter.cpp -o greeter_app

```  

>Run the application

```  
./greeter_app

```  

### Task 2: The Smart Swapper Utility
Objective

To understand and demonstrate the critical difference between pointers and references, two fundamental concepts in C++ that differ significantly from Java.
Core Concepts & Skills Gained

    Pointers (*): Declaring pointer variables that store memory addresses.

    Address-of Operator (&): Getting the memory address of a variable to assign to a pointer.

    Dereferencing (*): Accessing or modifying the value stored at a pointer's memory address.

    References (&): Creating an alias or a nickname for an existing variable.

    Pass-by-Pointer vs. Pass-by-Reference: Understanding the different syntax and use cases for modifying external variables from within a function.


> Compile the single source file

```  
g++ smart_swapper.cpp -o swapper_app
```  
> Run the application

```  
./swapper_app
```  
### Task 3: A Digital Bookshelf Entry
Objective

To build a well-structured C++ class with a clean separation of interface and implementation, and to learn the importance of const correctness for writing safer code.
Core Concepts & Skills Gained

    Class Structure: Reinforcing the .hpp/.cpp separation for professional code organization.

    Constructors: Using constructors to initialize an object's state upon creation, ensuring it's always in a valid state.

    Member Initializer Lists: The modern and efficient C++ way to initialize member variables in a constructor.

    const Correctness: Applying const to member functions that do not modify the object's state, allowing the compiler to enforce read-only access.


>Compile all source files

``` 
 g++ main.cpp Book.cpp -o bookshelf_app
```  

>Run the application

```  
./bookshelf_app
```  

### Task 4: The Resource Logger
Objective

To demonstrate and understand the core C++ resource management pattern: RAII (Resource Acquisition Is Initialization), which uses object lifetime to guarantee cleanup.
Core Concepts & Skills Gained

    Destructors (~ClassName()): Special methods that are automatically called when an object is destroyed.

    RAII: The principle of tying a resource's lifetime (like a file or network connection) to an object's lifetime. The resource is acquired in the constructor and released in the destructor.

    Object Scope & Lifetime: Understanding how an object's lifetime is determined by its scope (e.g., the curly braces {}) and how its destructor is automatically called when it goes out of scope.

>Compile the single source file

```  
g++ FileLogger.cpp -o logger_app
```  

>Run the application

```
./logger_app
```  

### Task 5: The Interactive Library Kiosk
Objective

To build a complete, interactive command-line application that manages a collection of objects using dynamic memory, reinforcing the need for manual memory management and proper class design.
Core Concepts & Skills Gained

    Composition: Building complex classes (Library, Book) that contain objects of other classes (Author).

    Dynamic Memory Allocation: Using new to create objects on the heap and storing them using pointers (Book*).

    Manual Memory Management: The critical responsibility of using delete to free any memory allocated with new to prevent memory leaks.

    Destructors for Cleanup: Implementing a destructor in the Library class to loop through and delete all the Book objects it owns.

    std::vector: Using the standard library's dynamic array to manage a collection of pointers.

    Application Logic: Building an interactive while loop, handling user input, and creating a text-based menu.

How to Compile & Run (with a Makefile)

```  
CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = library_app
SRCS = main.cpp Library.cpp Book.cpp Author.cpp
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

    ./library_app

### Task 6: The SOLID Notification System
Objective

To refactor a poorly designed, monolithic application into a clean, maintainable, and extendable system by applying the five SOLID design principles.
Core Concepts & Skills Gained

    Single Responsibility Principle (S): Each class has one, and only one, reason to change.

    Open/Closed Principle (O): Software entities should be open for extension but closed for modification.

    Liskov Substitution Principle (L): Subtypes must be substitutable for their base types without altering the correctness of the program.

    Interface Segregation Principle (I): Clients should not be forced to depend on interfaces they do not use.

    Dependency Inversion Principle (D): High-level modules should not depend on low-level modules; both should depend on abstractions.

    Polymorphism & Abstract Classes: Using interfaces (abstract base classes with pure virtual functions) to define a contract for a family of classes.

    Smart Pointers (std::unique_ptr): Using smart pointers to manage the memory of polymorphic objects, automating cleanup and preventing memory leaks (an upgrade from Task 5).



>Compile all source files for the good design

```  
g++ main.cpp EmailService.cpp SmsService.cpp -o solid_app

```  
>Run the application

```  
./solid_app

```  


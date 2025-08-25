#ifndef GREETER_H  // If GREETER_H has not been defined yet...
#define GREETER_H  // ...define it now.

#include <string> // We need to include this because our method uses the std::string type.

class Greeter {
    public: // This makes the following methods accessible to other parts of our code.
        // This is the method declaration. It tells the compiler that a method
        // named "say_hello" exists, it returns nothing (void), and it takes a
        // std::string as an argument.
        void say_hello(std::string user_name);
};

#endif // End of the include guard block.
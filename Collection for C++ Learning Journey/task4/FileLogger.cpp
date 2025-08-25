#include <iostream>
#include <string>

// A simple class that simulates managing a resource (like a file).
class FileLogger {
private:
    std::string filename;

public:
    // Constructor: Acquires the resource when the object is created.
    FileLogger(const std::string& name) : filename(name) {
        std::cout << "-> LOG: Opening " << filename << std::endl;
    }

    // Destructor: Releases the resource when the object is destroyed.
    ~FileLogger() {
        std::cout << "<- LOG: Closing " << filename << std::endl;
    }
};

int main() {
    std::cout << "Program starting." << std::endl;

    // We create a local scope with curly braces.
    {
        std::cout << "  Entering local scope." << std::endl;
        // The FileLogger object is created here. Its constructor runs.
        FileLogger logger("report.txt");
        std::cout << "  ...doing work inside scope..." << std::endl;
    } // The scope ends here. The 'logger' object is automatically destroyed,
      // and its destructor runs.

    std::cout << "Program has left the scope and is about to end." << std::endl;

    return 0;
}

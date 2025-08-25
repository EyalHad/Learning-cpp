#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// A simple object with three integers
class Color {
    int red, green, blue;
public:
    Color() : red(0), green(0), blue(0) {} // Default constructor for new[]
    void set(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
};


int main() {
    const int KB = 1024;
    const int SIZE = 20 * 1000 * KB;

    std::cout << "Before new. Allocating in C++" << SIZE << " Colors." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    Color* colors = new Color[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        colors[i].set(i % 256, (i * 2) % 256, (i * 3) % 256);
    }

    std::cout << "After new" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));

    delete[] colors;
}
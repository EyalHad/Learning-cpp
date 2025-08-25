# Compiler to use
CXX = g++

# Compiler flags:
# -std=c++17: Use the C++17 standard
# -Wall: Enable all compiler warnings
CXXFLAGS = -std=c++17 -Wall

# The name of the final executable
TARGET = swapper_app

# The single source file for this project
SRCS = smart_swapper.cpp

# Default rule: This is what runs when you just type 'make'
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up the directory
# Removes the executable file
clean:
	rm -f $(TARGET)


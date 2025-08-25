# 1. Variables
# CXX is the variable for the C++ compiler.
CXX = g++

# CXXFLAGS are the flags passed to the compiler.
# -std=c++17 sets the C++ standard.
# -Wall enables all compiler warnings (a very good practice).
CXXFLAGS = -std=c++17 -Wall

# TARGET is the name of the final executable file we want to create.
TARGET = library_app

# SRCS is the list of all our source (.cpp) files.
SRCS = main.cpp Library.cpp Book.cpp Author.cpp

# OBJS is a list of object (.o) files, created automatically from the source files list.
OBJS = $(SRCS:.cpp=.o)

# 2. Rules
# The 'all' rule is the default goal. When you just type 'make', this is what runs.
all: $(TARGET)

# This rule explains how to build the TARGET.
# It links all the object files together to create the final executable.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# This is a pattern rule that tells make how to create a .o file from a .cpp file.
# It compiles a single source file into an object file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# The 'clean' rule is a common utility to remove all generated files.
clean:
	rm -f $(OBJS) $(TARGET)

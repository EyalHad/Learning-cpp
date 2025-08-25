# 1. Variables

# CXX is the variable for the C++ compiler.
CXX = g++

# CXXFLAGS are the flags passed to the compiler.
# -std=c++17: sets the C++ standard.
# -Wall: enables all compiler warnings.
# -g: adds debugging information.
# -MMD -MP: These are the key flags for automatic dependency generation.
CXXFLAGS = -std=c++17 -Wall -g -MMD -MP

# --- Directories ---
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

# Add the include directory to the compiler flags so it knows where to find headers.
CXXFLAGS += -I$(INCLUDE_DIR)

# --- Project Files ---
# TARGET is the name of the final executable file, placed in the bin directory.
TARGET = $(BIN_DIR)/ledger_app

# SRCS automatically finds all .cpp files in the src directory.
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# OBJS creates a list of object files that will be placed in the obj directory.
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# DEPS creates a list of dependency files, also in the obj directory.
DEPS := $(OBJS:.o=.d)

# 2. Rules

# The 'all' rule is the default goal.
all: $(TARGET)

# This rule links all the object files to create the final executable.
# It depends on the object files and the existence of the bin directory.
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# This pattern rule compiles a .cpp file from src/ into a .o file in obj/.
# It depends on the existence of the obj directory.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# This rule creates the output directories if they don't exist.
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# The 'clean' rule removes all generated files and directories.
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* ledger.csv

# This line includes all the generated dependency files.
# The minus sign tells 'make' not to complain if the files don't exist yet.
-include $(DEPS)

# Phony targets are not files. 'all' and 'clean' are conventional phony targets.
.PHONY: all clean

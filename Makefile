# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/main.exe

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@

# Compile each .cpp file into a .o object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist (Windows version)
$(OBJ_DIR):
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(BIN_DIR):
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Clean up
clean:
	@if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)

.PHONY: all clean

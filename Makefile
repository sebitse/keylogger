# Name of the executable file
TARGET = keylogger

# Compiler to use
CXX = g++

# Compilation options
CXXFLAGS = -std=c++17 -Wall

# Source files
SRCS = main.cpp

# Object files generated from source files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build everything
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to generate object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean


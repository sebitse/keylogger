# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Target executable name
TARGET = KeyLogger

# Source files
SRCS = src/main.cpp \
       src/KeyLogger.cpp \
       src/SimpleLogStrategy.cpp \
       src/EncryptedLogStrategy.cpp \
       src/FormattedLogStrategy.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to link the object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove the generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets to prevent conflicts with files named 'all' or 'clean'
.PHONY: all clean

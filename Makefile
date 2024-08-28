# Compiler
CXX := g++

# Flags
CXXFLAGS := -Wall -Wextra -std=c++11

# Linker flags (for linking libraries)
LDFLAGS := -lX11 -lXtst

# Source code directory
SRCDIR := src

# Object file directory
BUILDDIR := build

# Executable target
TARGET := program

# Source file list
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Object file list
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Rule to build object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@ 

# Clean up build files
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Ensure that `clean` is not considered a file
.PHONY: clean

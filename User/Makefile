# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -IHeader -std=c++17 -Wall -Wextra

# Source files
SRC = $(wildcard Source/*.cpp) main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = app

# Default target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean


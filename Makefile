# Set the project name
PROJECT_NAME = vissort 

# Set the C++ compiler to clang++
CXX = clang++

# Set the flags for compilation 
CXXFLAGS = -std=c++17 -Wall -Wextra -Weverything -pedantic 

# Linker (optional, usually defaults to clang++)
LD = clang++

# Directories for object files, source files, and header files
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build
INCLUDE_DIR = include

# Find all the source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Find all the object files (replace .cpp with .o)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# The output executable
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# Default target: build the program
all: $(TARGET)

# Link the object files to create the final executable
# Additionally, link external libraries here as well
$(TARGET): $(OBJECTS)
	$(LD) $(OBJECTS) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system 

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Add a target for static analysis with clang-tidy
tidy:
	clang-tidy $(SOURCES) -- -I$(SRC_DIR) -I$(INCLUDE_DIR) -std=c++17


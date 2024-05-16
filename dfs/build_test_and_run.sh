#!/bin/bash

# Function to display error message and exit
function display_error {
    echo "Error: $1"
    exit 1
}

# Check if CMake and g++ are installed
command -v cmake >/dev/null 2>&1 || display_error "CMake is not installed. Please install CMake."
command -v g++ >/dev/null 2>&1 || display_error "g++ compiler is not installed. Please install g++."

# Create build directory if it doesn't exist
mkdir -p build || display_error "Failed to create build directory."

# Change to build directory
cd build || display_error "Failed to change to build directory."

# Run CMake to generate build files
cmake .. || display_error "Failed to run CMake."

# Build the project
echo
cmake --build . || display_error "Failed to build the project."

# Run the tests
echo
ctest || display_error "Tests failed."

# Run the program
echo
./bin/program || display_error "Failed to run the program."


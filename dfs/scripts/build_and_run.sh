#!/bin/bash

# Function to display error message and exit
function display_error {
    echo "Error: $1"
    exit 1
}

# Check if CMake and g++ are installed
command -v cmake >/dev/null 2>&1 || display_error "CMake is not installed. Please install CMake."

# Get the directory where the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Change to the parent directory of the script directory
cd "$SCRIPT_DIR/.." || display_error "Failed to change to project root directory."

# Create build directory if it doesn't exist
mkdir -p build || display_error "Failed to create build directory."

# Change to build directory
cd build || display_error "Failed to change to build directory."

# Run CMake to generate build files without tests
echo -e "\n[Running CMake to generate build files without tests...]"
cmake -DENABLE_TESTING=OFF .. || display_error "Failed to run CMake."

# Build the project
echo -e "\n[Building the project...]"
cmake --build . || display_error "Failed to build the project."

# Run the program
echo -e "\n[Running the program...]"
./bin/program || display_error "Failed to run the program."

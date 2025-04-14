#!/bin/sh

# Exit on error
set -e

echo "Running CMake configure script..."

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Run CMake with default options (customize if needed)
cmake ..

echo "Configuration complete."

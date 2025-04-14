#!/bin/bash

# Reconfiguring CMake
echo "🔁 Reconfiguring CMake..."
cmake -S . -B cmake-build-debug > /dev/null 2>&1  # Suppress regular output

# Build the project
echo "🔨 Building the project..."
cmake --build cmake-build-debug > /dev/null 2>&1  # Suppress regular output

# Formatting code with clang-format
echo "🔧 Formatting code with clang-format..."
# shellcheck disable=SC2038
find src tests \( -name '*.cpp' -o -name '*.h' \) | xargs clang-format -i  # Show processing files

echo ""

# Running cpplint
echo "🧼 Running cpplint..."
# shellcheck disable=SC2038
find src tests \( -name '*.cpp' -o -name '*.h' \) | xargs cpplint --linelength=119

echo ""

# Build tests
echo "🧪 Building tests..."
cmake --build cmake-build-debug --target test_runner > /dev/null 2>&1  # Only errors

# Run tests with working directory set to src
echo "🔧 Running tests with working directory set to src..."
(cd src && ../build/test_runner)

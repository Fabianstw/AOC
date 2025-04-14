cmake_minimum_required(VERSION 3.10)
project(AOC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# 👇 Add this line
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(main
        src/main.cpp
        src/D1/sol1.cpp
        src/D2/sol2.cpp
)

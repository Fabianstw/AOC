cmake_minimum_required(VERSION 3.10)
project(AOC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(main
        src/main.cpp
        src/D1/sol1.cpp
        src/D2/sol2.cpp
)

configure_file(src/D1/inp.txt inp.txt COPYONLY)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_runner
        tests/test_sol1.cpp
        src/D1/sol1.cpp
)

target_link_libraries(test_runner gtest_main)

include(GoogleTest)
gtest_discover_tests(test_runner)

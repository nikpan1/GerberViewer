cmake_minimum_required(VERSION 3.10)

# Project name
project(MyMathProject)

# Locate GTest package
find_package(GTest REQUIRED)

# Add include directories for GTest
include_directories(${GTEST_INCLUDE_DIRS})

# Add source files
# add_executable(myMath myMath.cpp)

# Add the test executable
add_executable(tests test_myMath.cpp)

# Link the test executable with GTest and myMath library
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()

# Add the test to the test suite
add_test(NAME myMathTest COMMAND tests)


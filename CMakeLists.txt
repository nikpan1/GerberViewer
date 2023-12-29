# --- CMake Template ---

# Minimum required version of CMake and Cpp 
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)


project(GerberViewer)

# external libraries
find_package(GTest REQUIRED)


# Source files
set(SOURCES
  src/main.cpp
  src/Parser.cpp
  src/Core.cpp
  src/Expression.cpp
)

# Header files
set(HEADERS
  include/Parser.h
  include/Expression.h
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}) 

target_include_directories(${PROJECT_NAME} PUBLIC include)


# Check the build type
if(CMAKE_BUILD_TYPE STREQUAL "Tests") 
  target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
  enable_testing()
  add_test(test ${PROJECT_NAME})
  target_compile_definitions(${PROJECT_NAME} PRIVATE gvDEBUG)
  message("Building in Tests mode.")

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Define functions for Debug mode
  target_compile_definitions(${PROJECT_NAME} PRIVATE gvDEBUG)
  message("Building in Debug mode.")

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  # Define functions for Release mode
  target_compile_definitions(${PROJECT_NAME} PRIVATE gvRELEASE)
  message("Building in Release mode.")

else()
  message(FATAL_ERROR "Unknown build type. Set CMAKE_BUILD_TYPE to Debug or Release.")

endif()


# Optionally, you can set additional compiler flags
# For example, enabling warnings
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Optionally, you can specify additional include directories
# target_include_directories(${PROJECT_NAME} PRIVATE include)

# Optionally, you can link against additional libraries
# For example, linking against the standard math library
# target_link_libraries(${PROJECT_NAME} PRIVATE m)


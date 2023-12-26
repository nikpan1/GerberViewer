# --- CMake Template ---

# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(GerberViewer)
# Source files
set(SOURCES
    src/main.cpp
    src/Parser.cpp
    src/Expression.cpp
)

# Header files
set(HEADERS
    include/Parser.h
    include/Expression.h
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


# Optionally, you can set additional compiler flags
# For example, enabling warnings
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Optionally, you can specify additional include directories
# target_include_directories(${PROJECT_NAME} PRIVATE include)

# Optionally, you can link against additional libraries
# For example, linking against the standard math library
# target_link_libraries(${PROJECT_NAME} PRIVATE m)


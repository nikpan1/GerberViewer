#!/bin/bash 
# Script to automate build process

# Check if there are at least two arguments
if [ "$#" != 1 ]; then
echo "Wrong input amount. You need to pass the CMAKE_BUILD_TYPE(Release | Debug | Tests)."
    exit 1
fi

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build 

# Run CMake to generate Makefiles
cmake -DCMAKE_BUILD_TYPE=$1 ..

# generate the autocompletion file
make clean && compiledb make all
mv compile_commands.json ..

# Run make to build the project
make





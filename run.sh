#!/bin/bash

# Define variables
BUILD_DIR="build"
EXECUTABLE="NetworkCommunication"

# Function to print usage
usage() {
    echo "Usage: $0 [build|run|test|clean]"
    echo "  build   - Build the project"
    echo "  run     - Run the built executable"
    echo "  test    - Run unit tests"
    echo "  clean   - Clean up build files"
    exit 1
}

# Build the project
build() {
    echo "Building the project..."
    mkdir -p $BUILD_DIR
    cd $BUILD_DIR || exit
    cmake ..
    make
    cd ..
    echo "Build complete."
}

# Run the executable
run() {
    echo "Running the application..."
    if [ -f "$BUILD_DIR/$EXECUTABLE" ]; then
        ./$BUILD_DIR/$EXECUTABLE
    else
        echo "Executable not found. Please build the project first."
        exit 1
    fi
}

# Run unit tests
test() {
    echo "Running unit tests..."
    cd tests || exit
    mkdir -p build
    cd build || exit
    cmake ..
    make
    ./test_network
    cd ../..
}

# Clean up build files
clean() {
    echo "Cleaning up build files..."
    rm -rf $BUILD_DIR
    cd tests || exit
    rm -rf build
    cd ..
    echo "Clean up complete."
}

# Check for valid arguments
if [ $# -ne 1 ]; then
    usage
fi

# Execute the appropriate function based on the argument
case $1 in
    build)
        build
        ;;
    run)
        run
        ;;
    test)
        test
        ;;
    clean)
        clean
        ;;
    *)
        usage
        ;;
esac


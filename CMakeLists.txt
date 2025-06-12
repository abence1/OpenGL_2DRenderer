cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include directories for dependencies
include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)

# Set the path for the library files
link_directories(${CMAKE_SOURCE_DIR}/dependencies/library)

# List all .cpp and .c files in the src directory
file(GLOB SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/glad.c
)

# Check if any source files are found
if(NOT SOURCE_FILES)
    message(FATAL_ERROR "No source files found!")
endif()

# Create an executable target
add_executable(app ${SOURCE_FILES})

# Link the necessary libraries and frameworks
target_link_libraries(app
    ${CMAKE_SOURCE_DIR}/dependencies/library/libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)

# Enable warnings and debugging symbols
target_compile_options(app PRIVATE -Wall -g -Wno-deprecated)

# Enable colored diagnostics (if supported by your compiler)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")


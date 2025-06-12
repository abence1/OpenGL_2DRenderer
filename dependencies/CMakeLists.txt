cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(MyApp)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Set debugging flags and enable colored diagnostics
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -fdiagnostics-color=always")

# Include directories
include_directories(
    ./dependencies/include
)

# Add the C++ source files (exclude glad.c)
set(SOURCES
    ./src/*.cpp
)

# Add the C source files (glad.c)
set(C_SOURCES
    ./src/glad.c
)

# Add executable
add_executable(app ${SOURCES} ${C_SOURCES})

# Treat glad.c as C file
set_source_files_properties(${C_SOURCES} PROPERTIES LANGUAGE C)

# Link libraries and frameworks
target_link_libraries(app
    ./dependencies/library/libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)

# Optionally, you can hide deprecated warnings
target_compile_options(app PRIVATE -Wno-deprecated)

# Link directories (for finding the .dylib files)
link_directories(./dependencies/library)


cmake_minimum_required(VERSION 3.13)  # CMake version check
project(itp_s2_lab2)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp student.h files.cpp files.h table.cpp table.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(itp_s2_lab2 ${SOURCE_FILES})
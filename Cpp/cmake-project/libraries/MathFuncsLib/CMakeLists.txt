# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(MathFuncsLib)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(MathFuncsLib src/MathFuncsLib.cpp)

target_include_directories(MathFuncsLib PRIVATE include/)

# Testing
enable_testing()

# Unit test with cunit
add_executable(test_io_gml test/CunitTest.cpp)
target_link_libraries(test_io_gml -lcunit MathFuncsLib)
target_include_directories(test_io_gml PRIVATE include/)
add_test(io_gml test_io_gml)

# Unit test with cunit + gcov
# https://jhbell.com/using-cmake-and-gcov
# https://github.com/jhbell/cmake-gcov
add_executable(test_io_gml_coverage test/CunitTest.cpp)
target_compile_options(test_io_gml_coverage PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries(test_io_gml_coverage -lcunit -fprofile-arcs -ftest-coverage MathFuncsLib)
target_include_directories(test_io_gml_coverage PRIVATE include/)
add_test(io_gml_coverage test_io_gml_coverage)
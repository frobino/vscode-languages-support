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
# NOTE: gcno files created at compile time, gcda files will be created once test are executed.
# TODO: fix the following line for gcov only?
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_executable(test_io_gml_coverage test/CunitTest.cpp src/MathFuncsLib.cpp)
target_compile_options(test_io_gml_coverage PRIVATE -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_link_libraries(test_io_gml_coverage -lcunit -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_include_directories(test_io_gml_coverage PRIVATE include/)
add_test(io_gml_coverage test_io_gml_coverage)

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
# gcov -b ../src/*.cpp -o CMakeFiles/test_io_gml_coverage.dir/src/
# lcov -c --directory . --output-file main_coverage.info
# genhtml main_coverage.info --output-directory out
add_custom_command(TARGET gcov
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${CMAKE_BINARY_DIR}/CMakeFiles/test_io_gml_coverage.dir/src/
    COMMAND lcov -c --directory ${CMAKE_BINARY_DIR} --output-file main_coverage.info
    COMMAND genhtml main_coverage.info --output-directory out
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)

# Create the gcov-clean target. This cleans the build as well as generated
# .gcda and .gcno files.
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    # COMMAND rm -f ${OBJECT_DIR}/*.gcno
    # COMMAND rm -f ${OBJECT_DIR}/*.gcda
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/test_io_gml_coverage.dir/src/*.gcno
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/test_io_gml_coverage.dir/src/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
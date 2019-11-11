# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(MathFuncsLib)

# Add a library to this build, i.e. this project will create a library (see "add executable" for main function).
# The name of the library is MathFuncsLib and it consists of only the MathFuncsLib.cpp file.
add_library(MathFuncsLib src/MathFuncsLib.cpp)
# Specify .h files directory of the library.
target_include_directories(MathFuncsLib PRIVATE include/)

# Testing
enable_testing()

###########################################
# NEW TARGET test_io_gml: unit test with cunit
#
# This target exclusively runs the unit tests and report pass/fail
#
# TODO: use "find_library" or "find_package" to check that the host system
#       has the "lib-cunit" package installed, otherwise shoot a message.
###########################################
add_executable(test_io_gml test/CunitTest.cpp)
target_link_libraries(test_io_gml -lcunit MathFuncsLib)
target_include_directories(test_io_gml PRIVATE include/)
add_test(io_gml test_io_gml)

###########################################
# NEW TARGET test_io_gml_coverage: Unit test with cunit + gcov
#
# This target runs the unit tests and generate coverage info files (gcno, gcda)
#
# NOTE: we are compiling test_io_gml_coverage without linking to the O3 MathFuncsLib!
#       See "target_link_libraries", where we do NOT specify MathFuncsLib.
#       We are instead adding the whole source files into the final executable (see "add_executable").
#       In this way, we make sure that the final executable will be compiled with O0 flag,
#       resulting in correct coverage results.
#
# Inspired from:
# https://jhbell.com/using-cmake-and-gcov
# https://github.com/jhbell/cmake-gcov
# NOTE: gcno files created at compile time, gcda files will be created once test are executed.
###########################################
# TODO: fix the following line for test_io_gml_coverage target only?
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_executable(test_io_gml_coverage test/CunitTest.cpp src/MathFuncsLib.cpp)
target_compile_options(test_io_gml_coverage PRIVATE -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_link_libraries(test_io_gml_coverage -lcunit -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_include_directories(test_io_gml_coverage PRIVATE include/)
add_test(io_gml_coverage test_io_gml_coverage)

###########################################
# NEW TARGET gcov: interprets the gcno, gcda files and generate html report
#
# This target requires that coverage info files (gcno, gcda) are present.
# It exectures the gcov, lcov, and genhtml commands and create a report in the "coverage" directory.
#
# TODO: add dependency of "gcov" target to "test_io_gml_coverage" target.
###########################################
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

###########################################
# NEW TARGET scrub: this cleans the build as well as generated .gcda and .gcno files.
###########################################
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    # COMMAND rm -f ${OBJECT_DIR}/*.gcno
    # COMMAND rm -f ${OBJECT_DIR}/*.gcda
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/test_io_gml_coverage.dir/src/*.gcno
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/test_io_gml_coverage.dir/src/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

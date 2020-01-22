# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Create a few variables to simplify renaming in the future
set(NAME_LIBRARY MathFuncsLib)
set(NAME_TEST1 test_io_gml)
file(GLOB proj_SRC
    "src/*.cpp"
)
file(GLOB test_SRC
    "test/*.cpp"
)

# Name of the project
project(${NAME_LIBRARY})

# Add a library to this build, i.e. this project will create a library (see "add executable" for main function).
# The name of the library is ${NAME_LIBRARY} and it consists of only the MathFuncsLib.cpp file.
# The library can be STATIC or SHARED. Default STATIC.
add_library(${NAME_LIBRARY} STATIC ${proj_SRC})
# Specify .h files directory of the library.
target_include_directories(${NAME_LIBRARY} PRIVATE include/)

# Testing: this creates a new rule (named test) in the Makefile.
# The test rule will execute (not build) all targets specified using the add_test() command
enable_testing()

###########################################
# NEW TARGET test_io_gml: unit test with cunit
#
# This target exclusively runs the unit tests and report pass/fail
#
# TODO: use "find_library" or "find_package" to check that the host system
#       has the "lib-cunit" package installed, otherwise shoot a message.
###########################################

add_executable(${NAME_TEST1} ${test_SRC})
target_link_libraries(${NAME_TEST1} -lcunit ${NAME_LIBRARY})
target_include_directories(${NAME_TEST1} PRIVATE include/)
add_test(io_gml ${NAME_TEST1})

###########################################
# NEW TARGET test_io_gml_coverage: Unit test with cunit + gcov
#
# This target runs the unit tests and generate coverage info files (gcno, gcda)
#
# NOTE: we are compiling test_io_gml_coverage without linking to the O3 ${NAME_LIBRARY}!
#       See "target_link_libraries", where we do NOT specify ${NAME_LIBRARY}.
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

add_executable(${NAME_TEST1}_coverage ${test_SRC} ${proj_SRC})
target_compile_options(${NAME_TEST1}_coverage PRIVATE -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_link_libraries(${NAME_TEST1}_coverage -lcunit -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_include_directories(${NAME_TEST1}_coverage PRIVATE include/)
add_test(io_gml_coverage ${NAME_TEST1}_coverage)

###########################################
# NEW TARGET gcov: interprets the gcno, gcda files and generate html report
#
# This target requires that coverage info files (gcno, gcda) are present.
# It exectures the gcov, lcov, and genhtml commands and create a report in the "coverage" directory.
#
# TODO: add dependency of "gcov" target to "test_io_gml_coverage" target.
###########################################

add_custom_target(gcov_${NAME_LIBRARY}
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} ${NAME_TEST1} ${NAME_TEST1}_coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

add_custom_command(TARGET gcov_${NAME_LIBRARY}
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${CMAKE_BINARY_DIR}/CMakeFiles/${NAME_TEST1}_coverage.dir/src/
    COMMAND lcov -c --directory ${CMAKE_BINARY_DIR} --output-file main_coverage.info
    COMMAND genhtml main_coverage.info --output-directory out
    COMMAND xdg-open out/index.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)

###########################################
# NEW TARGET scrub: this cleans the build as well as generated .gcda and .gcno files.
###########################################
add_custom_target(scrub_${NAME_LIBRARY}
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/${NAME_TEST1}_coverage.dir/src/*.gcno
    COMMAND rm -f ${CMAKE_BINARY_DIR}/CMakeFiles/${NAME_TEST1}_coverage.dir/src/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

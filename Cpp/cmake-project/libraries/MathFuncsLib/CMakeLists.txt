# Inspired by tutorial:
# https://ncona.com/2019/03/building-a-cpp-project-with-cmake/

# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Create a few variables, used to make this file modular
set(LIB_NAME MathFuncsLib)
set(LIB_H_DIR include/)
file(GLOB LIB_SRC
    "src/*.cpp"
)
set(TEST1_NAME test_${LIB_NAME}_operations)
file(GLOB TEST_SRC
    "test/*.cpp"
)

# Name of the project (which will be the 1st default target)
project(${LIB_NAME})

# Add all the source files needed to build.
# Use add_library command to specify the creation of a library file (so/a/dll).
# The library can be STATIC or SHARED. Default STATIC.
add_library(${LIB_NAME} STATIC ${LIB_SRC})

# Specify directories of header files needed to build.
target_include_directories(${LIB_NAME} PRIVATE ${LIB_H_DIR})

# Testing: this creates a new rule (named test) in the Makefile.
# The test rule will execute (not build) all targets specified using the add_test() command,
# including the ones from subprojects/subdirectories/modules
enable_testing()

###########################################
# NEW TARGET ${TEST1_NAME}:
# create executable for unit test with cunit.
#
# Running the generated executable will:
# - run the unit tests and report pass/fail
#
# TODO: use "find_library" or "find_package" to check that the host system
#       has the "lib-cunit" package installed, otherwise shoot a message.
###########################################

add_executable(${TEST1_NAME} ${TEST_SRC})
target_link_libraries(${TEST1_NAME} -lcunit ${LIB_NAME})
target_include_directories(${TEST1_NAME} PRIVATE ${LIB_H_DIR})
add_test(${TEST1_NAME} ${TEST1_NAME})

###########################################
# NEW TARGET ${TEST1_NAME}_coverage:
# create executable for unit test with cunit + coverage info with gcov (gcno file)
#
# Running the generated executable will:
# - run the unit tests and report pass/fail
# - create a gcna file with test coverage info, ready to be parsed into human readable format
#
# NOTE: we are compiling test_io_gml_coverage without linking to the O3 ${LIB_NAME}!
#       See "target_link_libraries", where we do NOT specify ${LIB_NAME}.
#       We are instead adding the whole source files into the final executable (see "add_executable").
#       In this way, we make sure that the final executable will be compiled with O0 flag,
#       resulting in correct coverage results.
#
# Inspired from:
# https://jhbell.com/using-cmake-and-gcov
# https://github.com/jhbell/cmake-gcov
#
# NOTE: gcno files created at compile time, gcda files will be created once test are executed.
###########################################

# TODO: fix the following line for ${TEST1_NAME}_coverage target only?
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

add_executable(${TEST1_NAME}_coverage ${TEST_SRC} ${LIB_SRC})
target_compile_options(${TEST1_NAME}_coverage PRIVATE -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_link_libraries(${TEST1_NAME}_coverage -lcunit -fprofile-arcs -ftest-coverage -g -O0 -Wall)
target_include_directories(${TEST1_NAME}_coverage PRIVATE ${LIB_H_DIR})
add_test(${TEST1_NAME}_coverage ${TEST1_NAME}_coverage)

###########################################
# NEW TARGET gcov_${LIB_NAME}:
#
# - trigger the build of all test, including the *coverage ones, generating static coverage info (gcno)
# - trigger the execution of all test, including the *coverage ones, generating dynamic coverage info (gcna)
# - a custom command interprets the gcno, gcda files and generate html report into the coverage directory
#
###########################################

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/coverage)

# create a dependency on the custom command.
# In this specific case, running the CUSTOM_COMMAND
# will trigger the build and execution of tests
add_custom_target(gcov_${LIB_NAME}
    # COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} ${TEST1_NAME} ${TEST1_NAME}_coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

add_custom_command(TARGET gcov_${LIB_NAME}
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp
    COMMAND lcov -c --directory ${CMAKE_CURRENT_BINARY_DIR} --output-file main_coverage.info
    COMMAND genhtml main_coverage.info --output-directory out
    COMMAND xdg-open out/index.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)

###########################################
# NEW TARGET scrub: this cleans the build as well as generated .gcda and .gcno files.
###########################################
add_custom_target(scrub_${LIB_NAME}
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${TEST1_NAME}_coverage.dir/src/*.gcno
    COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${TEST1_NAME}_coverage.dir/src/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

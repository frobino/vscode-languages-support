# Inspired by tutorial:
# https://ncona.com/2019/03/building-a-cpp-project-with-cmake/

# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Create a few variables, used to make this file modular
set(PROJECT_NAME Project)
file(GLOB PROJECT_SRC_FILE
    "main.cpp"
)
set(LIB1_DIR libraries/MathFuncsLib)
set(LIB1_H_DIR ${LIB1_DIR}/include/)
set(MODULE1_DIR module1)
set(MODULE1_H_DIR ${MODULE1_DIR}/include/)
file(GLOB MODULE1_SRC_FILE
    "module1/src/*.cpp"
)

# Name of the project (which will be the 1st default target)
project(${PROJECT_NAME} VERSION 1.0
  DESCRIPTION "Very nice project"
  LANGUAGES CXX)

# Add all the source files needed to build.
# Use add_executable command to specify the creation of an exe file.
add_executable(
  ${PROJECT_NAME}
  ${PROJECT_SRC_FILE}
  ${MODULE1_SRC_FILE}
)

# Include the directory where MathFuncsLib project is.
# Otherwise, we can't use the library.
add_subdirectory(${LIB1_DIR})
add_subdirectory(${MODULE1_DIR})

# Link the executable and the library together
target_link_libraries(${PROJECT_NAME} MathFuncsLib)

# Specify directories of header files needed to build.
target_include_directories(${PROJECT_NAME} PRIVATE ${LIB1_H_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${MODULE1_H_DIR})

# Testing: this creates a new rule (named test) in the Makefile.
# The test rule will execute (not build) all targets specified using the add_test() command,
# including the ones from subprojects/subdirectories/modules
enable_testing()
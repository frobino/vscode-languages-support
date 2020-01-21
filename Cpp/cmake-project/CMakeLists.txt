# Inspired by tutorial:
# https://ncona.com/2019/03/building-a-cpp-project-with-cmake/

# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project (which will be the 1st default target)
project(Project VERSION 1.0
  DESCRIPTION "Very nice project"
  LANGUAGES CXX)

# Create a few variables for the folder names, so they are easier to rename in the future
set(LIBRARIES_DIR libraries)

# Add all the source files needed to build the executable
add_executable(
  Project
  main.cpp
)

# Include the directory where MathFuncsLib project is.
# Otherwise, we can't use the library.
add_subdirectory(${LIBRARIES_DIR}/MathFuncsLib)

# Link the executable and the library together
target_link_libraries(Project MathFuncsLib)
target_include_directories(Project PRIVATE ${LIBRARIES_DIR}/MathFuncsLib/include/)

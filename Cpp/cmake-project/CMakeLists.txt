# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(Project)

# Create a few variables for the folder names, so they are easier to rename in
# the future
#set(HELPERS_DIR src/helpers)
#set(MODELS_DIR src/models)

# Add all the source files needed to build the executable
add_executable(
  Project
  main.cpp
#  ${HELPERS_DIR}/AwesomeHelper.cpp
#  ${HELPERS_DIR}/OkHelper.cpp
#  ${MODELS_DIR}/Person.cpp
)

# Include the directory where MathFuncsLib project is. Otherwise, we can't use the
# library
add_subdirectory(libraries/MathFuncsLib)

# Link the executable and the library together
target_link_libraries(Project MathFuncsLib)

target_include_directories(Project PRIVATE libraries/MathFuncsLib/include/)
# How to build

From a folder containing CMakeLists.txt (e.g. main folder, library folder or module folder), run:

  mkdir build && cd build && cmake ..
  make VERBOSE=1

# Naming conventions

Namespace is <project>::<module>::<class>

# Notes

As it is currently configured in CMakeLists.txt:
- make test is available only if we build from the libraries/<libName> folder;
- make test can be executed only after make (testName or all) has been executed;
- make gcov can be executed only after make test has been executed, i.e. the tests have been executed and gcno/gcda has been generated;
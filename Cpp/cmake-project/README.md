# How to build

From a folder containing CMakeLists.txt (e.g. main folder, library folder or module folder), run:

  mkdir build && cd build && cmake ..
  make VERBOSE=1

or:

  mkdir Release && cd Release
  cmake -DCMAKE_BUILD_TYPE=Release ..
  make VERBOSE=1

  mkdir Debug
  cd Debug
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  make VERBOSE=1

# Naming conventions

Namespace is <project>::<module>::<class>
Libraries are named <something>Lib, and the namespace is the <something> (see boost library)

# Project features:

Unit and functional tests + coverage (implemented in the gcov_* targets):

- cunit
- gcov + lcov

Performance test (TODO):

- gprof (not good fo multithreaded)
- gperftools (require code instrumentation)
- valgrind-callgrind + kcachegrind:
  $ valgrind --tool=callgrind path/to/your/compiled/program program_arguments
  $ kcachegrind calgrind.out.12345
  Look into Self, showing the time spent in each function itself discounting the callees

Memory usage test (TODO):

- valgrind-memcheck:
  $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test


# Notes

As it is currently configured in CMakeLists.txt:
- make test is available only if we build from the libraries/<libName> folder;
- make test can be executed only after make (testName or all) has been executed;
- make gcov can be executed only after make test has been executed, i.e.:
  * the tests have been executed and gcno/gcda has been generated;
  * make gcov can run only from the libraries/<libName> folder;
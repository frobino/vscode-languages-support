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

One possible namespace convention is:
  <project>::<module>::<class>
  <project>::<library>::<class>

Libraries:
- placed under library/<SomeThing>Lib folder
- named <SomeThing>Lib.[cpp|h|hpp]
- the namespace is the <something>

Modules
- placed under modules/<SomeThing> folder
- the namespace is the <something>

More complex conventions can be used if the project grows.
Other libs such as std, boost and soundtouch projects use similar approaches.

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

# Notes and TODO

As it is currently configured in CMakeLists.txt:
- make test is available only if we build from the libraries/<libName> folder;
- make test can be executed only after make (testName or all) has been executed;
- make gcov can be executed only after make test has been executed, i.e.:
  * the tests have been executed and gcno/gcda has been generated;
  * make gcov_MathFuncsLib can run only from the libraries/<libName> folder;

TODO - Yeoman generator:
- this project can be ported to a yeoman generator, to improve usage (i.e. no "git clone")

TODO - bin/debug folders and rules for binary generation
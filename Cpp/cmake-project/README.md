# How to build

From a folder containing CMakeLists.txt (e.g. main folder or library folder), run:

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

# How to run

After building execute one of the following:

Execute all unit and funcional test, and generate coverage info:

    make test

Visualize coverage info for a specific module:

    make gcov_* # name of project, library or module

# Cpp project naming conventions

One possible namespace convention is:

    *project*::*module*::*class*

or 

    *project*::*library*::*class*

Libraries:
- placed under library/*SomeThing*Lib folder
- named *SomeThing*Lib.[cpp|h|hpp]
- the namespace is the *something*

Modules
- placed under modules/*SomeThing* folder
- the namespace is the *something*

More complex conventions can be used if the project grows.
Other libs such as std, boost and soundtouch projects use similar approaches.

# Project features:

## Unit and functional tests

- cunit

## Coverage visualization

Implemented in the gcov_* targets.

Execute targets in this order:
- test_*testName*_coverage: builds test with extra flags, generating static info (gcno)
- test: executest the test, generating runtime info (gcda)
- gcov_*moduleName*: executes gcov to interpret gcda and gcdo files, and lcov + htmlgen to pretty print

## Performance test (TODO):

- valgrind-callgrind + kcachegrind:

      $ valgrind --tool=callgrind path/to/your/compiled/program program_arguments
      $ kcachegrind calgrind.out.12345
  
  Look into Self, showing the time spent in each function itself discounting the callees

## Memory usage test (TODO):

- valgrind-memcheck:

      $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test

## Packet management inclusion (TODO)

- conan or vcpkg

# Notes and additional TODOs

As it is currently configured in CMakeLists.txt:
- make test can be executed only after make (testName or all) has been executed;
- make gcov* rules can be executed only after make test has been executed, i.e. the tests have been executed and gcno/gcda has been generated;

TODO - Yeoman generator (or Python cookiecutter):
- this project can be ported to a yeoman generator, to improve usage (i.e. no "git clone")

TODO - bin/debug folders and rules for binary generation
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([points_use], [1], [/dev/null])

AM_INIT_AUTOMAKE
LT_INIT

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])

# Checks for header files.
AC_CHECK_HEADERS([stddef.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_FUNC_OBSTACK
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_FSEEKO
AC_CHECK_FUNCS([getdelim sqrt])

AC_CONFIG_FILES([Makefile])

AC_CONFIG_SUBDIRS
AC_OUTPUT

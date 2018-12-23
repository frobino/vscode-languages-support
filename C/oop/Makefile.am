AM_CFLAGS=-g -O3 -Wall -fms-extensions
AM_LDFLAGS=-lm

lib_LTLIBRARIES=libpoints.la
libpoints_la_SOURCES=point.c threepoint.c

include_HEADERS=point.h threepoint.h

bin_PROGRAMS=points_use
points_use_SOURCES=points_use.c
points_use_LDADD=libpoints.la

# TESTS=$(check_PROGRAMS)
# check_PROGRAMS=points_test
# dict_test_LDADD=libpoints.la

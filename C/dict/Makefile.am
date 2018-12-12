AM_CFLAGS=-g -O3 -Wall `pkg-config --cflags glib-2.0`
AM_LDFLAGS=`pkg-config --libs glib-2.0`

lib_LTLIBRARIES=libdict.la
libdict_la_SOURCES=dict.c keyval.c

include_HEADERS=keyval.h dict.h

bin_PROGRAMS=dict_use
dict_use_SOURCES=dict_use.c
dict_use_LDADD=libdict.la

TESTS=$(check_PROGRAMS)
check_PROGRAMS=dict_test
dict_test_LDADD=libdict.la

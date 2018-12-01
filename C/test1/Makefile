##############################
# V1] Classic makefile
#
# However, by using the default rules of make:
#	make -p > default_rules
# It is possible to reduce the text even more.
# See V2.
##############################
#
# CC=gcc
# FLAGS=-c -Wall -g
# 
# all: test1
# 
# test1: test1.o
# 	${CC} test1.o -o test1
# 
# test1.o: test1.c
# 	${CC} ${FLAGS} test1.c
# 
# clean:
# 	rm -rf *.o test1

##############################
# V2] Makefile using make default rules
#
# $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $*.c
##############################

P=test1
OBJECTS=
CFLAGS =-g -Wall -O3
LDLIBS=
CC=gcc

$(P): $(OBJECTS)

clean:
	rm -rf *.o $(P)
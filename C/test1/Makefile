CC=gcc
FLAGS=-c -Wall -g

all: test1

test1: main.o
	${CC} main.o -o test1

main.o: main.c
	${CC} ${FLAGS} main.c

clean:
	rm -rf *.o test1
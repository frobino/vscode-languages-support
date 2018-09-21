CXX=g++
FLAGS=-c -Wall -g

all: main.x

main.x: main.o
	${CXX} main.o -o main.x

main.o: main.cpp
	${CXX} ${FLAGS} main.cpp

clean:
	rm -rf *.o main.x
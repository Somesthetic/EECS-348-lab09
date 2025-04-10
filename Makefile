#
CC=g++ # Defines which compiler we're using
CFLAGS=-c -Wall

all: prog

prog: main.o matrix.o
	$(CC) main.o matrix.o -o result_prog # Says: compile all of these together, going to each, and save the
	# executable to result_prog

main.o: main.cpp matrix.hpp# Once prog calls this, it runs this, with main.c being a dependency
	$(CC) $(CFLAGS) main.cpp # compiles main.c

matrix.o: matrix.hpp

clean:
	rm -rf *.o # Removes any file that ends in .o, using regex stuff
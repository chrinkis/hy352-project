CC = g++
CFLAGS = -std=c++11 -g

SRC = $(wildcard src/**/*.cpp)
SRC2 = $(wildcard src/**/*/*.cpp)
INCUDE=$(wildcard include/jsonlang/*.h)

jsonlang: $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(SRC2) -I include/ -I include/jsonlang -c

lib: $(wildcard *.o)
	ar rvs jsonlang.a $(wildcard *.o)

demo:
	$(CC) $(CFLAGS) test/main.cpp jsonlang.a -o demo.out -I include/

clean:
	-rm -f ./*.o ./*.out jsonlang.a

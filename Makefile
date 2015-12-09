#Makefile
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++0x -w

all:  src/rshell.cpp
	mkdir bin
	g++ $(CFLAGS) -o bin/rshell src/rshell.cpp

rshell: src/rshell.cpp
	mkdir bin
	g++ $(CFLAGS) -o bin/rshell src/rshell.cpp
  
clean:
	rm bin/rshell; rmdir bin

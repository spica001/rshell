#makefile

all: rshell
	mkdir -p ./bin

rshell:
	g++ -std=c++11 -Wall -Werror -ansi -pedantic ./src/rshell.cpp -o ./bin/rshell

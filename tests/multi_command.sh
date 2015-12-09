Script started on Tue 08 Dec 2015 08:26:03 PM PST
[spica001@hammer rshell]$ make
mkdir bin
g++ -ansi -pedantic -Wall -Werror -std=c++0x -w -o bin/rshell src/rshell.cpp
[spica001@hammer rshell]$ bin/rshell
spica001@hammer.cs.ucr.edu $ ls && echo A
bin  clean.sh  LICENSE	Makefile  multi.sh  README.md  src  tests  test.sh
A
spica001@hammer.cs.ucr.edu $ ls && echo A && echo B
bin  clean.sh  LICENSE	Makefile  multi.sh  README.md  src  tests  test.sh
A
B
spica001@hammer.cs.ucr.edu $ ls && echo A || echo B
bin  clean.sh  LICENSE	Makefile  multi.sh  README.md  src  tests  test.sh
A
spica001@hammer.cs.ucr.edu $ echo|A||| echo B
A
spica001@hammer.cs.ucr.edu $ echooA; echo B; echo C
A
B
C
spica001@hammer.cs.ucr.edu $
spica001@hammer.cs.ucr.edu $ echo C || ls
C
spica001@hammer.cs.ucr.edu $ exit
[spica001@hammer rshell]$ exit
exit

Script done on Tue 08 Dec 2015 08:30:39 PM PST

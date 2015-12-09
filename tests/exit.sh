Script started on Tue 08 Dec 2015 08:48:30 PM PST
[spica001@hammer rshell]$ bin/rshell
spica001@hammer.cs.ucr.edu $ echo A $
A
spica001@hammer.cs.ucr.edu $ exit
[spica001@hammer rshell]$ bin/rshell
spica001@hammer.cs.ucr.edu $ echo A && exit
A
[spica001@hammer rshell]$ bin/rshell
spica001@hammer.cs.ucr.edu $ echo A || exit
A
spica001@hammer.cs.ucr.edu $ echo B #&& exit
B
spica001@hammer.cs.ucr.edu $ echo B; exit
B
[spica001@hammer rshell]$ exit
exit

Script done on Tue 08 Dec 2015 08:52:32 PM PST

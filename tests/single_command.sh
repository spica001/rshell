Script started on Tue 08 Dec 2015 07:36:02 PM PST
0;spica001@hammer:~/rshell[spica001@hammer rshell]$ ls
LICENSE	 Makefile  README.md  src  test	 test.sh
0;spica001@hammer:~/rshell[spica001@hammer rshell]$ make
mkdir bin
g++ -ansi -pedantic -Wall -Werror -std=c++0x -w -o bin/rshell src/rshell.cpp
0;spica001@hammer:~/rshell[spica001@hammer rshell]$ bin/rshell
spica001@hammer.cs.ucr.edu $ echo Hello
Hello
spica001@hammer.cs.ucr.edu $ ls
bin  LICENSE  Makefile	README.md  src	test  test.sh
spica001@hammer.cs.ucr.edu $ git status
# On branch master
# Your branch is ahead of 'origin/master' by 1 commit.
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	LICENSE
#	bin/
#	src/a.out
#	src/log.txt
#	src/spica001
#	test.sh
nothing added to commit but untracked files present (use "git add" to track)
spica001@hammer.cs.ucr.edu $ cd test
Error: Exec Failed: No such file or directory
spica001@hammer.cs.ucr.edu $ cal
    December 2015
Su Mo Tu We Th Fr Sa
       1  2  3	4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

spica001@hammer.cs.ucr.edu $ git log
commit f11c58815b7594213a711a1a8f3102a6eedec0a2
Author: spica001 <spica001@ucr.edu>
Date:	Tue Dec 8 19:34:27 2015 -0800

    MASSIVE UPDATE

commit 3b12982e6a52de9d2912be5e76b2de307ec7e9b6
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 16:57:14 2015 -0800

     Maybe it fixed?

commit 3f05cc0dd9cc81ff2de9aca3a0e191f92cd35821
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 13:26:57 2015 -0800

    update for extra credit

commit 9a23fd794148937942f9b59936335b62be27c5d0
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 13:16:46 2015 -0800

    Update ReadME

commit 3b59091907e5e8cffccfd359623f22b2fe6f8878
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 13:13:27 2015 -0800

    Add README and Makefile template

commit fe74bed8813e9b332d31500984d99ae6d223b845
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 13:04:39 2015 -0800

    Removed lingering rshell.cpp

commit e51c44e68b5debcd1c9f689a647e93939fcbd491
Author: spica001 <spica001@ucr.edu>
Date:	Fri Nov 6 13:01:57 2015 -0800

spica001@hammer.cs.ucr.edu $
spica001@hammer.cs.ucr.edu $ ls -a
.  ..  bin  .git  LICENSE  Makefile  README.md	src  test  test.sh
spica001@hammer.cs.ucr.edu $ ls -al
total 68
drwxr-xr-x  6 spica001 csmajs  4096 Dec	 8 19:36 .
drwx------ 13 spica001 csmajs  4096 Dec	 8 19:30 ..
drwxr-xr-x  2 spica001 csmajs  4096 Dec	 8 19:36 bin
drwxr-xr-x  8 spica001 csmajs  4096 Dec	 8 19:34 .git
-rw-r--r--  1 spica001 csmajs 35147 Nov	 7 00:01 LICENSE
-rw-r--r--  1 spica001 csmajs	255 Dec	 8 19:30 Makefile
-rw-r--r--  1 spica001 csmajs  1371 Dec	 8 17:29 README.md
drwxr-xr-x  4 spica001 csmajs  4096 Dec	 8 17:26 src
drwxr-xr-x  2 spica001 csmajs  4096 Dec	 8 19:18 test
-rw-r--r--  1 spica001 csmajs	  0 Dec	 8 19:36 test.sh
spica001@hammer.cs.ucr.edu $ clear
spica001@hammer.cs.ucr.edu $ vim t.txt
▽  "t.txt" [New File]  1
"t.txt" [New] 2L, 7C written													      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  ~																	~																      ~																	    ~																	  0,0-1AllH e l l o -- INSERT --2,1All	2 i21H2e3l4l5o6^[  2,5All::wq
spica001@hammer.cs.ucr.edu $ lsss
bin  LICENSE  Makefile	README.md  src	test  test.sh  t.txt
spica001@hammer.cs.ucr.edu $ rm t.txt
spica001@hammer.cs.ucr.edu $ ls
bin  LICENSE  Makefile	README.md  src	test  test.sh
spica001@hammer.cs.ucr.edu $ exit
0;spica001@hammer:~/rshell[spica001@hammer rshell]$ exit
exit

Script done on Tue 08 Dec 2015 07:40:16 PM PST

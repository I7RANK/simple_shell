##Simple_shell

This project is meant to recreat a shell (mini shell) with some of the concepts, functions and system calls that we have gotten during this period of time.

###Compilate files are compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

###Some of the system calls and functions used in this project:

execve
exit
fork
free
getline
isatty
malloc
perror
strtok
wait
write

###Description files
| Files | Description |
| ------------ | ------------ |
| Builtin.c | Files to find and execute built-in |
| create_linked.c | Linked list to manage the PATH |
| main.c | Main functions, to print the prompt, to execute execve and to set the arguments |
| mini_shell.h | Header file |
| _puts.c  | copy of puts functions and function to change int to string  |

###Examples

####simple_shell examples
`$ ls -la`
`total 44`
`drwxr-xr-x 1 runner runner 126 Aug 17 00:57 .`
`drwxr-xr-x 1 runner runner 4096 Aug 17 00:38 ..`
`-rw-r--r-- 1 runner runner 38 Aug 16 22:45 _puts.c`
`-rw-r--r-- 1 runner runner 2225 Aug 16 22:43 builtin.c`
`-rw-r--r-- 1 runner runner 2381 Aug 16 22:44 create_linked.c`
`-rw-r--r-- 1 runner runner 2153 Aug 16 17:01 error.html`
`-rwxr-xr-x 1 runner runner 13648 Aug 17 00:57 main`
`-rw-r--r-- 1 runner runner 3285 Aug 16 22:44 main.c`
`-rw-r--r-- 1 runner runner 1084 Aug 16 22:44 mini_shell.h`

`$ pwd`
`/home/runner/cIsFun`


###Project flowchart
[![Flowchar_simple_shell](https://github.com/I7RANK/simple_shell/blob/master/general_flowchart.jpg "Flowchar_simple_shell")](http://https://github.com/I7RANK/simple_shell/blob/master/general_flowchart.jpg "Flowchar_simple_shell")

Authors
Silena Restrepo [Twitter](https://twitter.com/silenarestrepo_"link title"):fa-twitter-square: :fa-star:
Francisco Guzmán [Twitter](https://twitter.com/I7RANKI"link title") :fa-twitter-square: :fa-music:
Lilibeth Tabares [Twitter](https://twitter.com/LilibethTabares"link title") :fa-twitter-square: :fa-heart:

###Links of interest

[Tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/-"link title")  Write a Shell in C
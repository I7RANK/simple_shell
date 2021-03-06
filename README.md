## Simple_shell
This project is meant to recreat a shell (mini shell) with some of the concepts, functions and system calls that we studied during this period of time.

------------
### Download the repository

Git clone `https://github.com/I7RANK`

------------

### Compilate files are compiled this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

------------

### RUN

Usage `./hsh`

------------
### Some of the system calls and functions used in this project:
- execve
- exit
- fork
- free
- getline
- isatty
- malloc
- perror
- strtok
- wait
- write

------------


### Description files 📂

| Files  | Description  |
| ------------ | ------------ |
| Builtin.c  |  Files to find and execute built-in |
| create_linked.c  |  Linked list to manage the PATH |
| main.c	| Main functions, to print the prompt, to execute execve and to set the arguments |
| mini_shell.h | Header file |
| _puts.c | copy of puts functions and function to change int to string |
| init.arguments. c | to allocate memory to the arguments |
| free_all.c | to free all the memory allocated |
| AUTHORS | file with the authors |
| README.md | the README  of the repo |
| flowchart(1).png | image of the flowchart |
| man_1_simple_shell | man of this mini_shell |


------------


### Examples

####
`$ ls -la` <br/>
`total 44`  <br/>
`drwxr-xr-x 1 runner runner 126 Aug 17 00:57 .` <br/>
`drwxr-xr-x 1 runner runner 4096 Aug 17 00:38 ..`  <br/>
`-rw-r--r-- 1 runner runner 38 Aug 16 22:45 _puts.c`  <br/>
`-rw-r--r-- 1 runner runner 2225 Aug 16 22:43 builtin.c`  <br/>
`-rw-r--r-- 1 runner runner 2381 Aug 16 22:44 create_linked.c` <br/>
`-rw-r--r-- 1 runner runner 2153 Aug 16 17:01 error.html`  <br/>
`-rwxr-xr-x 1 runner runner 13648 Aug 17 00:57 main`  <br/>
`-rw-r--r-- 1 runner runner 3285 Aug 16 22:44 main.c` <br/>
`-rw-r--r-- 1 runner runner 1084 Aug 16 22:44 mini_shell.h`  <br/>


`$ pwd` <br/>
`/home/runner/cIsFun` <br/>
`$ ` <br/>


------------


### Project flowchart
Flowchar_simple_shell
[![Flowchart_simple_shell](https://github.com/I7RANK/simple_shell/blob/master/flowchart%20(1).jpg "Flowchart_simple_shell")](https://github.com/I7RANK/simple_shell/blob/master/flowchart%20(1).jpg "Flowchart_simple_shell")


------------


### Authors
- Silena Restrepo [https://twitter.com/silenarestrepo_] 🌺
- Francisco Guzmán [https://twitter.com/I7RANKI] 🐈
- Lilibeth Tabares [https://twitter.com/LilibethTabares] 🌻

#### End of README.md

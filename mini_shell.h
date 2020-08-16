#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

/**
 * struct path - struct path
 * @s: it's the string
 * @next: it's the next node
*/
typedef struct path
{
	char *s;
	struct path *next;
} path_st;

/**
 * struct built - the struct to the built-ins
 * @name: the name of the built-in
 * @func: the function to the built-in
*/
typedef struct built
{
	char *name;
	int (*func)(char **argv, int c, char *n);
} built_in;

/* ========== PROTOTYPES ========== */
/* create_linked.c */
path_st *create_linkedlist_path(char *path);
void _new_node(char *s, path_st **head);
path_st *create_node(char *s);
void free_PATH(path_st *head);
char *_getenv(const char *name);

/* builtin.c */
int mini_exit(char **argv, int c, char *n);
int mini_cd(char **argv, int c, char *n);
int mini_env(char **argv, int c, char *n);
int find_builtin(char **argv, built_in *built_names, int c, char *n);

#endif /* MINI_SHELL_H */

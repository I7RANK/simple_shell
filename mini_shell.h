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
 * struct _free - struct that will have the pointers to free
 * @f_header_PATH: linked list that will have the PATH
 * @f_buff_line: string set by get line
 * @f_arguments: arguments to free
*/
typedef struct _free
{
	path_st **f_header_PATH;
	char **f_buff_line;
	char ***f_arguments;
} tofree_st;

/**
 * struct built - the struct to the built-ins
 * @name: the name of the built-in
 * @func: the function to the built-in
 */
typedef struct built
{
	char *name;
	int (*func)(char **argv, int c, tofree_st tofree, char *n);
} built_in;

/* ========== PROTOTYPES ========== */
/* main.c */
int execute_execve(path_st *header, char *const argv[]);
void set_argv(char **argv, char *buff, const char *delim);
void print_error(int count, char *name, char *command);

/* create_linked.c */
path_st *create_linkedlist_path(char *path);
void _new_node(char *s, path_st **head);
path_st *create_node(char *s);
void free_PATH(path_st *head);
char *_getenv(const char *name);

/* builtin.c */
int mini_exit(char **argv, int c, tofree_st tofree, char *n);
int mini_cd(char **argv, int c, tofree_st tofree, char *n);
int mini_env(char **argv, int c, tofree_st tofree, char *n);
int find_builtin(char **argv, built_in *b, int c, tofree_st t, char *n);
int _strcmp(char *s1, char *s2);

/* _puts.c */
int _puts(char *str);
char *tostring(char *scount, int count);

/* THE OTHERS */
/* init_arguments.c */
char **init_arguments(void);

/* free_all.c */
void free_all(tofree_st tofree);

#endif /* MINI_SHELL_H */

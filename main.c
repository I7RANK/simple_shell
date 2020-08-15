#include "mini_shell.h"

int execute_execve(path_st *header, char *const argv[]);
void set_argv(char **argv, char *buff);
char *save_name(char *src);
void print_error(int count, char *name, char *command);

/**
 * main - main function
 * @argc: number of arguments but for now not passed arguments
 * @argv: the array of pointers to fill with set_argv
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	path_st *header_PATH = NULL;
	ssize_t sizes = 0;
	size_t BUFF1024 = 0;
	char *buff_line = NULL, *myname = NULL;
	int status, err_count = 0;

	myname = save_name(argv[0]);
	header_PATH = create_linkedlist_path(_getenv("PATH"));

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		err_count++;
		sizes = getline(&buff_line, &BUFF1024, stdin);
		if (sizes == -1)
		{
			/* Free the memory */
			free_PATH(header_PATH);
			free(buff_line);

			exit(EXIT_SUCCESS);
		}
		set_argv(argv, buff_line);

		if (fork() == 0)
		{
			if (execute_execve(header_PATH, argv) != 0)
			{
				print_error(err_count, myname, argv[0]);
			}
		}
		wait(&status);
	}

	(void)status;
	(void)argc;
	return (0);
}

/**
 * execute_execve - try execut the command with all path_st
 * @header: it's the linked list of the environment variable path
 * @argv: it's the array of arguments and the command
 *
 * Return: 0
 */
int execute_execve(path_st *header, char *const argv[])
{
	int s1, s2;
	path_st *temp = header;
	char path_command[100];

	while (temp)
	{
		for (s2 = 0; temp->s[s2]; s2++)
		{
			path_command[s2] = temp->s[s2]; /* agregar el path de las rutas */
		}

		path_command[s2] = '/'; /* agregar el slash */

		s2++;
		for (s1 = 0; argv[0][s1]; s1++, s2++)
		{
			path_command[s2] = argv[0][s1]; /* agregar el comando */
		}
		path_command[s2] = '\0'; /* agregar el NULL */


		execve(path_command, argv, NULL);

		temp = temp->next;
	}

	if (execve(argv[0], argv, NULL))
	{
		return (1);
	}

	return (0);
}

/**
 * set_argv - initialize @argv
 * Description: with the string obtained in the getline() function
 * @argv: it's the array of pointer to fill
 * @buff: it's the string teken by getline()
 *
 * Return: na
 */
void set_argv(char **argv, char *buff)
{
	char *token = NULL;
	int i;

	for (i = 0; buff[i]; i++)
	{}
	buff[i - 1] = '\0';

	token = strtok(buff, " \t");

	for (i = 0; token != NULL; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " \t");
	}

	free(token);

	argv[i] = NULL;
}

/**
 * save_name - saves the name of this mini_shell
 * @src: it's the name to copy
 *
 * Return: na
*/
char *save_name(char *src)
{
	char *dest;
	int i, j = 0;

	for (i = 2; src[i]; i++)
	{}

	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
	{
		printf("Error in memory allocation");
		exit(EXIT_FAILURE);
	}

	for (i = 2; src[i]; i++, j++)
	{
		dest[j] = src[i];
	}
	dest[j] = '\0';

	return (dest);
}

/**
 * print_error - prints a error
 * @count: the number of error
 * @name: the name of this program
 * @command: the command that caused the error
*/
void print_error(int count, char *name, char *command)
{
	printf("%s: %d: %s: not found\n", name, count, command);

	/*
	* El valor 127 se devuelve /bin/sh
	* cuando el comando dado no se encuentra
	* dentro de la PATH variable de su sistema
	* y no es un comando de shell incorporado.
	* En otras palabras, el sistema no comprende su comando,
	* porque no sabe dónde encontrar el binario
	* que está tratando de llamar.
	*/
	exit(127);
}

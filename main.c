#include "mini_shell.h"

int execute_execve(path_st *header, char *const argv[]);
void set_argv(char **argv, char *buff);
char *_getenv(const char *name);

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
	char *buff_line = NULL;
	int status;

	header_PATH = create_linkedlist_path(_getenv("PATH"));

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		sizes = getline(&buff_line, &BUFF1024, stdin);
		if (sizes == -1)
		{
			/* Free the memory */
			free_PATH(header_PATH);
			free(buff_line);

			printf("%ld\n", sizes);
			perror("");
			exit(EXIT_FAILURE);
		}
		set_argv(argv, buff_line);

		if (fork() == 0)
		{
			execute_execve(header_PATH, argv);
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
		perror("Error");
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: it's the name of the environment variable to find
 * Return: the value or NULL if not found
 */
char *_getenv(const char *name)
{
	char **p, *str;
	int i = 0, j = 0;

	for (p = __environ; *p; p++, i++)
	{
		str = *p;
		if (str[0] == name[0])
		{
			for (j = 0; str[j] != '='; j++)
			{
				if (str[j] != name[j])
				{
					break;
				}
			}
			if (str[j] == '=')
			{
				return (&str[j + 1]);
			}
		}
	}
	return (NULL);
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

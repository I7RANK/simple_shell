#include "mini_shell.h"

int execute_execve(path_st *header, char *const argv[]);
void set_argv(char **argv, char *buff, const char *delim);
char *save_name(char *src);
void print_error(int count, char *name, char *command);

/**
 * main - main function
 * @argc: number of arguments but for now not passed arguments
 * @argv: the array of pointers to fill with set_argv
 * Return: 0
 */
int main(int argc, char **argv)
{
	path_st *header_PATH = NULL;
	ssize_t sizes = 0;
	size_t BUFF1024 = 0;
	char *buff_line = NULL, *myname = NULL;
	int status, err_count = 0;
	char **arguments = NULL;

	built_in declare_builtin[] = {
		{"exit", mini_exit},
		{"env", mini_env},
		{"cd", mini_cd},
		{NULL, NULL}
	};

	tofree_st tofree;
	tofree.f_buff_line = &buff_line;
	tofree.f_header_PATH = &header_PATH;
	tofree.f_myname = &myname;
	tofree.f_arguments = &arguments;

	arguments = init_arguments();
	myname = save_name(argv[0]);
	header_PATH = create_linkedlist_path(_getenv("PATH"));

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		err_count++;
		sizes = getline(&buff_line, &BUFF1024, stdin);
		if (sizes == -1)
		{
			free_all(tofree);

			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		set_argv(arguments, buff_line, " \t");
		if (arguments[0] != NULL)
		{
			if (find_builtin(arguments, declare_builtin, err_count, tofree) == 0)
			{
				if (fork() == 0)
				{
					if (execute_execve(header_PATH, arguments) != 0)
					{
						print_error(err_count, myname, arguments[0]);
					}
				}
			}
		}
		wait(&status);
	}
	(void)argc;
	return (0);
}

/**
 * execute_execve - try execut the command with all path_st
 * @header: it's the linked list of the environment variable path
 * @argv: it's the array of arguments and the command
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
			path_command[s2] = temp->s[s2];
		}

		path_command[s2] = '/';

		s2++;
		for (s1 = 0; argv[0][s1]; s1++, s2++)
		{
			path_command[s2] = argv[0][s1];
		}
		path_command[s2] = '\0';

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
 * @delim: is the delimiter to the @buff
 * Return: void
 */
void set_argv(char **arguments, char *buff, const char *delim)
{
	int i, j, conargv = 0;
	char *token = buff;

	for (i = 0; buff[i]; i++)
	{}
	if (buff[i - 1] == '\n')
	{
		buff[i - 1] = '\0';
	}

	i = 0;
	token = strtok(str, delim);

	i++;
    /* walk through other tokens */
    while (token != NULL)
	{
		arguments[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	/* for (i = 0; buff[i]; i++)
	{
		if (token == NULL)
		{
			token = &buff[i];
		}
		for (j = 0; delim[j]; j++)
		{
			if (buff[i] == delim[j])
			{
				buff[i] = '\0';
				if (token[0] != '\0')
				{
					arguments[conargv] = token;
					conargv++;
					token = NULL;
				}
				else
				{
					token = NULL;
				}
			}
			if (buff[i + 1] == '\0')
			{
				arguments[conargv] = token;
			}
		}
	}
	conargv++;
	arguments[conargv] = NULL; */
}

/**
 * save_name - saves the name of this mini_shell
 * @src: it's the name to copy
 * Return: dest
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
		_puts("Error in memory allocation\n");
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
 * @command: the command that caused the error
 * @name: the name of this program
 */
void print_error(int count, char *name, char *command)
{
	char scount[150];

	tostring(scount, count);
	_puts(name);
	_puts(": ");
	_puts(scount);
	_puts(": ");
	_puts(command);
	_puts(": not found\n");

	exit(127);
}

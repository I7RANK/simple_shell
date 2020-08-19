#include "mini_shell.h"

int _strcmp(char *s1, char *s2);

/**
 * find_builtin - function to find built-in
 * @argv: arguments to enter
 * @built_names: names of the built-in
 * @c: counter variable
 * @n: pointer to name of the executable without /
 * Return: 0
 */
int find_builtin(char **argv, built_in *built_names, int c, char *n)
{
	int i;

	for (i = 0; built_names[i].name; i++)
	{
		if (_strcmp(built_names[i].name, argv[0]) == 0)
		{
			return (built_names[i].func(argv, c, n));
		}
	}
	(void)c;
	(void)n;
	return (0);
}

/**
 * mini_exit - function to implement exit built-in
 * @argv: arguments
 * @c: the counter to errors
 * @n: the name of this program
 * Return: 0 or other number if fails
 */

int mini_exit(char **argv, int c, char *n)
{
	int status = 0, i;
	char cstring[120];

	if (argv[1] != NULL)
	{
		for (i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] < 48 || argv[1][i] > 57)
			{
				tostring(cstring, c);
				_puts(n);
				_puts(": ");
				_puts(cstring);
				_puts(": ");
				_puts("exit: Illegal number: ");
				_puts(argv[1]);
				_puts("\n");

				return (-1);
			}
		}
		for (i = 0; argv[1][i]; i++)
		{
			status = status * 10 + (argv[1][i] - '0');
		}
	}
	(void)c;
	(void)n;
	exit(status);
} 

/**
 * mini_env - prints the environment variables of this program
 * @argv: arguments
 * @c: the conter to errors
 * @n: the name of this program
 * Return: 0 or other number if fails
 */
int mini_env(char **argv, int c, char *n)
{
	int i;

	if (argv[1] != NULL)
	{
		_puts(argv[0]);
		_puts(": ");
		_puts(argv[1]);
		_puts(": No such file or directory\n");
	
		return (-1);
	}
	for (i = 0; __environ[i] != NULL; i++)
	{
		_puts(__environ[i]);
		_puts("\n");
	}
	(void)c;
	(void)n;
	return (1);
}

/**
 * mini_cd - function to implement cd built-in
 * @argv: arguments
 * @c: the conter to errors
 * @n: the name of this program
 * Return: 0 or other number if fails
 */
int mini_cd(char **argv, int c, char *n)
{
	int dir_value = 0;

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (!argv[1])
		{
			dir_value = chdir("..");
			if (dir_value != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		dir_value = chdir(argv[1]);

		if (dir_value != 0)
		{
			printf("%s: %s: No such file or directory\n", argv[0], argv[1]);
			return (1);
		}
		return (1);
	}
	(void)argv;
	(void)c;
	(void)n;
	return (-1);
}

/**
 * _strcmp - compares two strings
 * Description: work exactly like strcmp
 * @s1: is the first string to comparate
 * @s2: is the second string to comparate
 * Return: returns one integer
 */
int _strcmp(char *s1, char *s2)
{
	int counter;

	for (counter = 0; s1[counter] != '\0'; counter++)
	{
		if (s1[counter] != s2[counter])
		{
			return (s1[counter] - s2[counter]);
		}
	}
	return (0);
}

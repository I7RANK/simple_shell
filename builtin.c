#include "mini_shell.h"

/**
 * find_builtin - function to find built-in
 * @argv: arguments to enter
 * @bn: names of the built-in
 * @c: counter variable
 * @tofree: the struct that has de pointers to free
 * @n: name
 * Return: 0
 */
int find_builtin(char **argv, built_in *bn, int c, tofree_st tofree, char *n)
{
	int i;

	for (i = 0; bn[i].name; i++)
	{
		if (_strcmp(bn[i].name, argv[0]) == 0)
		{
			return (bn[i].func(argv, c, tofree, n));
		}
	}
	(void)c;
	return (0);
}

/**
 * mini_exit - function to implement exit built-in
 * @argv: arguments
 * @c: the counter to errors
 * @n: name
 * @tofree: the struct that has de pointers to free
 * Return: 0 or other number if fails
 */
int mini_exit(char **argv, int c, tofree_st tofree, char *n)
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

				exit(2);
			}
		}
		for (i = 0; argv[1][i]; i++)
		{
			status = status * 10 + (argv[1][i] - '0');
		}
	}
	free_all(tofree);
	exit(status);
}

/**
 * mini_env - prints the environment variables of this program
 * @argv: arguments
 * @c: the conter to errors
 * @n: name
 * @tofree: the struct that has de pointers to free
 * Return: 0 or other number if fails
 */
int mini_env(char **argv, int c, tofree_st tofree, char *n)
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
	(void)n;
	(void)c;
	(void)tofree;
	return (1);
}

/**
 * mini_cd - function to implement cd built-in
 * @argv: arguments
 * @c: the conter to errors
 * @n: name
 * @tofree: the struct that has de pointers to free
 * Return: 0 or other number if fails
 */
int mini_cd(char **argv, int c, tofree_st tofree, char *n)
{
	(void)n;
	(void)argv;
	(void)c;
	(void)tofree;
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

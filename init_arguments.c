#include "mini_shell.h"

char **init_arguments(void)
{
	char **arguments = NULL;

	arguments = malloc(sizeof(arguments) * 120);
	if (arguments == NULL)
	{
		_puts("fail memory allocation\n");
		exit(EXIT_FAILURE);
	}
	return (arguments);
}
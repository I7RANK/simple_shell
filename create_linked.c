#include "mini_shell.h"

/**
 * _print_PATH - print each directory passed as argument. one per line
 * @path: it's the path
 *
 * Return: na
*/
path_st *create_linkedlist_path(char *path)
{
	path_st *header = NULL;
	char *token, *cp_path;
	int i, j;

	if (path == NULL)
	{
		return (NULL);
	}

	for (j = 0; path[j]; j++)
	{}

	cp_path = malloc(sizeof(char) * j);
	if (path == NULL)
	{
		return (NULL);
	}

	for (i = 0; path[i]; i++)
	{
		cp_path[i] = path[i];
	}
	cp_path[i] = 0;

	token = strtok(cp_path, ":");

	while (token != NULL)
	{
		_new_node(token, &header);
		token = strtok(NULL, ":");
	}

	free(cp_path);
	return (header);
}

/**
 * _new_node - creates a new node in the linked list
 * @s: the string to save in the node
 * @head: it's the header of the linked list
 * Return na
*/
void _new_node(char *s, path_st **head)
{
	path_st *temp = NULL, *new = NULL;
	int i = 0;

	new = create_node(s);

	if (*head == NULL)
	{
		*head = new;
		return;
	}

	temp = *head;

	for (i = 0; temp->next; i++)
	{
		temp = temp->next;
	}

	temp->next = new;
}

/**
 * create_node - creates and initializes a new node
 * @s: the string to initializes the new node
 *
 * Return: a pointer of the new node of NULL if fail
*/
path_st *create_node(char *s)
{
	path_st *new;
	int i;

	new = malloc(sizeof(path_st));
	if (new == NULL)
	{
		printf("error creating node\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; s[i]; i++)
	{
	}

	new->s = malloc(sizeof(char) * i);
	if (new->s == NULL)
	{
		printf("error creating node\n");
		free(new);
		exit(EXIT_FAILURE);
	}

	for (i = 0; s[i]; i++)
	{
		new->s[i] = s[i];
	}

	new->next = NULL;

	return (new);
}

/**
 * free_PATH - frees a listint_t list
 * @head: is the header of the linked list
 *
 * Return: na
 */
void free_PATH(path_st *head)
{
	if (head)
	{
		free_PATH(head->next);
		free(head->s);
		free(head);
	}
}

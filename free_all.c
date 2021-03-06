#include "mini_shell.h"

/**
 * free_all - this free all memory allocates
 * @tofree: the structs that contains the pointers
 *
 * Return: nothing
*/
void free_all(tofree_st tofree)
{
	free_PATH(tofree.f_header_PATH[0]);
	free(tofree.f_buff_line[0]);
	free(tofree.f_arguments[0]);
}

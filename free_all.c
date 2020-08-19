#include "mini_shell.h"

void free_all(tofree_st tofree)
{
	free_PATH(tofree.f_header_PATH[0]);
	free(tofree.f_buff_line[0]);
	free(tofree.f_myname[0]);
	free(tofree.f_arguments[0]);
}
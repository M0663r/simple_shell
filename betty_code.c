#include "shell.h"
/**
 *write_str- prints string
 *@str:const parameter
 *Return:0
 */
void write_str(const char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, &str, strlen(str));
		str += 1;
	}
}

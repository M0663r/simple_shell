#include "shell.h"

/**
 *_print - prints to standard output
 *@text_output:parameter
 *Return:void
 */
void _print(const char *text_output)
{
write(STDOUT_FILENO, text_output, strlen(text_output));
}

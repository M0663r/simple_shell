#include "shell.h"
/**
 * read_input - read user input
 * getline - built in function
 * @s:size
 * @command:pointer parameter
 *
 * Return:0
*/
char read_input(char *command, size_t s)
{
ssize_t scan;
command = NULL;
s = 0;
scan = getline(&command, &s, stdin);
if (scan == -1)
{
if (!feof(stdin))
{
perror("Read Failed");
exit(EXIT_FAILURE);
}
else
{
perror("End of file reached");
exit(EXIT_SUCCESS);
}
}
return (*command);
}

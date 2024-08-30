#include "shell.h"
/**
 * print_input - parse string
 *@command:string arguments parameter
 *@arg_cmd:value parameter
 * Return:0
*/
char print_input(char *command, char **arg_cmd, int tally)
{
char *tkn;
tally = 0;
tkn = strtok(command, " ");
while (tkn != NULL)
{
arg_cmd[tally] = tkn;
tally++;
tkn = strtok(NULL, " ");
}
return (**arg_cmd);
}

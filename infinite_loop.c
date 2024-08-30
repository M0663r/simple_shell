#include "shell.h"
#define SIZE 200
/**
 * infinite_loop - loops all functions for shell execution
 *
 * Return:0
*/
void infinite_loop(void)
{

int status;
char *command[SIZE];
char **args;
do {
char *prompt = "Lisa__sh $ > ";
write(STDOUT_FILENO, &prompt, strlen(prompt));

read_input(command, SIZE);
print_input(command);
status = exec_cmd(args);

free(command);
free(args);

} while (status);
}

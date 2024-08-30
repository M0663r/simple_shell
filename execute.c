#include "shell.h"

/**
 * execute_command - Executes a command by forking a child process
 * @argv: Argument vector containing the command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **argv)
{
pid_t child_pid;
char *command_path;

if (argv[0] == NULL)
{
return (-1);
}
command_path = find_command_in_path(argv[0]);
if (command_path == NULL)
{
perror("./shell");
return (-1);
}
child_pid = fork();
if (child_pid == 0)
{
execve(command_path, argv, environ);
perror("./shell");
exit(EXIT_FAILURE);
}
else if (child_pid < 0)
{
perror("fork");
return (-1);
}
else
{
wait(NULL);
}

if (command_path != argv[0])
{
free(command_path);
}
return (0);
}


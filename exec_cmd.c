#include "shell.h"
/**
 *exec_cmd -function that executes command in child proces
 *@args:arguments for commands
 *Return:nothing
*/
int exec_cmd(char **args)
{
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("Child process creation error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
char *arg_cmd[2];
arg_cmd[0] = (char *)args;
arg_cmd[1] = NULL;
if (execve(args[0], args, NULL) < 0)
{
perror("Command execution failed!!.\n");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(child_pid, &status, 0);
}
return (1);
}

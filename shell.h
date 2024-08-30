#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define PATH_MAX_LEN 1024

extern char **environ;

char *find_command_in_path(char *command);
int execute_command(char **argv);
void print_env(void);

#endif /* SHELL_H */

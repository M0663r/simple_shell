#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define MAX_ARGS 64
#define PATH_MAX_LEN 1024

char *find_command_in_path(char *command);

/**
 * main - entry point for code
 * Return: 0
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *argv[MAX_ARGS];
char *token;
int i;
pid_t child_pid;
char *command_path;


while (1)
{
printf(":) ");

nread = getline(&line, &len, stdin);

if (nread == -1)
{
printf("\n");
break;
}

line[nread - 1] = '\0';

token = strtok(line, " ");
for (i = 0; token != NULL && i < MAX_ARGS - 1; i++)
{
argv[i] = token;
token = strtok(NULL, " ");
}
argv[i] = NULL;

command_path = find_command_in_path(argv[0]);
if (command_path == NULL)
{
perror("./shell");
continue;
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
}
else
{
wait(NULL);
}

if (command_path != argv[0])
{
free(command_path);
}
}

free(line);
return (0);
}

char *find_command_in_path(char *command)
{
char *path = getenv("PATH");
char *path_dup = strdup(path);
char *dir = strtok(path_dup, ":");
struct stat st;
char full_path[PATH_MAX_LEN];

if (strchr(command, '/') != NULL)
{
if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
{
free(path_dup);
return (command);
}
}

while (dir != NULL)
{
snprintf(full_path, PATH_MAX_LEN, "%s/%s", dir, command);
if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
{
free(path_dup);
return (strdup(full_path));
}
dir = strtok(NULL, ":");
}

free(path_dup);
return (NULL);
}


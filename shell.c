#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

#define MAX_ARGS 64

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

while (1)
{
printf("#cisfun$ ");
        
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
        
if (execve(argv[0], argv, environ) == -1)
{
perror("./shell");
}
}
    
free(line);
return 0;
}


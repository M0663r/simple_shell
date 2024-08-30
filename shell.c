#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *argv[2];
    
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
        
argv[0] = line;
argv[1] = NULL;
        
if (execve(argv[0], argv, environ) == -1)
{
perror("./shell");
}
}
    
free(line);
return (0);
}


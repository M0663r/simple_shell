#include "shell.h"

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

if (argv[0] == NULL)
{
continue;
}
if (strcmp(argv[0], "env") == 0)
{
print_env();
}
else
{
execute_command(argv);
}
}

free(line);
return (0);
}


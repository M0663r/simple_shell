#include "shell.h"

/**
 * find_command_in_path - Finds a command in the system's PATH
 * @command: The command to find
 *
 * Return: The full path to the command, or NULL if not found
 */
char *find_command_in_path(char *command)
{
char *path = getenv("PATH");
char *path_dup = strdup(path);
char *token;
char full_path[PATH_MAX_LEN];
struct stat st;

token = strtok(path_dup, ":");
while (token != NULL)
{
snprintf(full_path, PATH_MAX_LEN, "%s/%s", token, command);
if (stat(full_path, &st) == 0)
{
free(path_dup);
return strdup(full_path);
}
token = strtok(NULL, ":");
}
free(path_dup);

return (NULL);
}


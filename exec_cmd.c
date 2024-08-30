#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "$ "

/**
 * exec_cmd - Entry point for the shell
 * Return: Always 0
 */
int exec_cmd(void)
{
    char buffer[BUFFER_SIZE];
    char *command;
    pid_t pid;
    int status;

    while (1)
    {
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
        {
            if (feof(stdin))
            {
                write(STDOUT_FILENO, "\n", 1);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("fgets");
                continue;
            }
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0] == '\0')
        {
            continue;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            execlp(buffer, buffer, (char *)NULL);
            perror(buffer);
            exit(EXIT_FAILURE);
        }
        else
        {
            do
            {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}


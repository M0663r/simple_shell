#ifndef MAINSHELL_H
#define MAINSHELL_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void write_str(const char *str);
void _print(const char *text_output);
void infinite_loop(void);
char read_input(char *command, size_t s);
char print_input(char *command, char **arg_cmd, int tally);
int exec_cmd(char **args);


#endif /*MAINSHELL_H*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64
#define MAX_PATH_LEN 1024

size_t _strlen(char *str);
void print_prompt(char *prompt);
int is_exit_command(char *cmd);
void append_cwd(char *cmd);

#endif /* MAIN_H */

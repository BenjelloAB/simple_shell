#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

#include <string.h>

#define TOKEN_DELIMITER " \t\n"

extern char **environ;

typedef void (*CommandFunc)(char **cmd, int *status, char **argv, int counter);

/**
 * struct CommandMapping - data to check for the built-in functions
 * @command: the command
 * @func: the function to run
 */
typedef struct CommandMapping
{
	char *command;
	CommandFunc func;
} CommandMapping;

/* == strings_utils.c == */
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* == strings_utils2.c ==*/
char *_strchr(char *s, char c);
void _trim(char *str);

/* == _strtok.c == */
unsigned int is_delim(char c, char *delim);
char *_strtok(char *srcString, char *delim);

/* == prints_utils.c == */
void print_prompt(char *prompt);
void print_error(char *name, char *buffer, int counter);
char *_itoa(int n);
int _atoi(char *str);

/* == utils.c == */
void _free(char **arr);
void free_and_null(char *path);
char *_getenv(char *var_name);
int check_if_positive(char *str);

/* == command.c == */
char *read_command(void);
char **tokenize_command(char *line);
int execute_command(char **cmd, char **argv, int counter);

/* == find_executable.c == */
char *find_executable(char *cmd);

/* == builtin.c == */
int builtin_command(char **cmd, char **argv, int counter, int *status);
void exit_shell(char **cmd, int *status, char **argv, int counter);
void print_env(char **cmd, int *status, char **argv, int counter);

#endif /* MAIN_H */


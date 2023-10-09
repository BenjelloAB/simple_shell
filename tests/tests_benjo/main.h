#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strlen(char *str);
void print_env();
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *get_path(char *va);
char *get_full_command(char *cmd);
char *clean_parenth(char *buf);
char **argem(char *buf);
#endif


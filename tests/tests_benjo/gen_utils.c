#include "main.h"
/**/
void print_env()
{
    extern char **environ;
    int i = 0;

    while(environ[i])
    {
        printf("%s\n",environ[i]);
        i++;
    }
}
/**/
char *get_path(char *va)
{
    extern char **environ;
    int i = 0;
    char *token;
    char *copy = NULL;
    while (environ[i])
    {
        copy = malloc(sizeof(char) * (_strlen(environ[i]) + 1));
        if(!copy)
            printf("Not enough memory");
        _strcpy(copy, environ[i]);
        token = strtok(copy, "=");
        if (strcmp(token, va) == 0)
            return (strtok(NULL, "="));
        free(copy);
        i++;
    }
    return NULL;
}
/**/
char *get_full_command(char *cmd)
{
    char *token;
    char *cmd_full = NULL;
    char *path1 = get_path("PATH");
    if (!path1)
    {
        printf("Error: PATH environment variable not found.\n");
        return NULL;
    }
    token = strtok(path1, ":");
    while (token)
    {
        cmd_full = malloc(sizeof(char) * (strlen(token) + strlen(cmd) + 2));
        if (cmd_full == NULL)
            return NULL;
        _strcpy(cmd_full, token);
        _strcat(cmd_full, "/");
        _strcat(cmd_full, cmd);
        if (access(cmd_full, F_OK) == 0)
        {
            return cmd_full;
        }
        free(cmd_full);
        token = strtok(NULL, ":");
    }
    return NULL;
}
/**/
char *clean_parenth(char *buf)
{
    int i = 0, si = -1, ei = -1, k = 0;
    char *s = malloc(sizeof(char *) * (_strlen(buf) + 2));
    if (!s)
        return NULL;
    while (buf[i])
    {
        if (buf[i] == '(')
            si = i;
        if (buf[i] == ')')
        {
            ei = i;
            break;
        }
        i++;
    }
    if (si == -1 || ei == -1)
    {
        free(s);
        return NULL;
    }
    for (i = si + 1; i < ei; i++)
    {
        s[k] = buf[i];
        k++;
    }
    s[k] = '\0';
    return s;
}
/**/
char **argem(char *buf)
{
    char *getrid = NULL;
    char *token = NULL;
    int i = 0, len = 0;
    char *buf_copy = NULL;
    char **av;
    if (!buf)
        return NULL;
    getrid = clean_parenth(buf);
    if (getrid != NULL)
    {
        free(buf);
        buf = getrid;
    }
    buf_copy = malloc(sizeof(char) * (strlen(buf) + 1));
    if (!buf_copy)
        return NULL;
    _strcpy(buf_copy, buf);
    token = strtok(buf_copy, " \t\n");
    while (token)
    {
        len = len + (strlen(token) * sizeof(char *)) + 1;
        token = strtok(NULL, " \t\n");
    }
    av = malloc(sizeof(char *) * (len + 1));
    if (!av)
        return NULL;
    free(buf_copy);
    buf_copy = malloc(sizeof(char) * (strlen(buf) + 1));
    if (!buf_copy)
        return NULL;
    _strcpy(buf_copy, buf);
    token = strtok(buf_copy, " \t\n");
    while (token)
    {
        av[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if (!av[i])
            return NULL;
        token = strtok(NULL, " \t\n");
        i++;
    }
    i = 0;
    token = strtok(buf, " \t\n");
    while (token)
    { 
        _strcpy(av[i], token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    av[i] = NULL;
    return av;
}

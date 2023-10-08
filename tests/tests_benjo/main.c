#include "main.h"
char *clean_parenth(char *buf)
{
    int i = 0, si = -1, ei = -1, k = 0;
    char *s = malloc(sizeof(char *) * (strlen(buf) + 2));
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
    if(getrid != NULL)
    {
        free(buf);
        buf = getrid;
    }
    buf_copy = malloc(sizeof(char) * (strlen(buf) + 1));
    if (!buf_copy)
        return NULL;
    strcpy(buf_copy, buf);
    token = strtok(buf_copy, " \t\n");
    while (token)
    {
        len++;
        token = strtok(NULL, " \t\n");
    }
    av = malloc(sizeof(char *) * (len + 1));
    if (!av)
        return NULL;
    free(buf_copy);
    buf_copy = malloc(sizeof(char) * (strlen(buf) + 1));
    if (!buf_copy)
        return NULL;
    strcpy(buf_copy, buf);
    token = strtok(buf_copy, " \t\n");
    while (token)
    {
        av[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if(!av[i])
            return NULL;
        token = strtok(NULL, " \t\n");
        i++;
    }
    i = 0;
    token = strtok(buf, " \t\n");
    while (token)
    {
        strcpy(av[i], token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    av[i] = NULL;
    free(buf_copy);
    return av;
}

int main(int argc, char **av, char **env)
{
    char *buffer = NULL;
    size_t size = 0;
    char **argv = NULL;
    pid_t pid;
    int chars = 0;
    char *full_path = NULL;
    int ex;
    char *token = NULL;

    while (1)
    {
        if (isatty(STDIN_FILENO) != 0)
        {

            write(1, "$ ", 2);
        }
        chars = getline(&buffer, &size, stdin);
        if (chars == -1)
        {
            exit(0);
        }
        else if (chars > 1)
        {

            buffer[chars - 1] = '\0';
            argv = argem(buffer);
            if (argv[0] == NULL)
               continue
            if (strcmp(buffer, "exit") == 0)
                exit(0);
            pid = fork();
            if (pid == 0)
            {
                ex = execve(argv[0], argv, NULL);
                if (ex == -1)
                    printf("./shell: No such file or directory\n");
                exit(1);
            }

            else if (pid != 0)
            {
                wait(NULL);
            }
         }   
    
    }
    free(buffer);
    return 0;
}

#include "main.h"
int main(void)
{
    char *buffer = NULL;
    char *full_cmd;
    size_t size = 0;
    char **argv = NULL;
    pid_t pid;
    int chars = 0;
    int ex;

    while (1)
    {
        if (isatty(STDIN_FILENO) != 0)
        {

            write(1, "$ ", 2);
        }
        chars = getline(&buffer, &size, stdin);
        if (chars == -1)
            exit(0);
        if (chars > 1)
        {
            buffer[chars - 1] = '\0';
            argv = argem(buffer);
            /* only spaces case */
            if (argv[0] == NULL)
                continue;
            /* exit case no args */
            if (strcmp(buffer, "exit") == 0)
                exit(0);
            if (strcmp(buffer, "env") == 0)
            {
                print_env();
                continue;
            }
            full_cmd = get_full_command(argv[0]);
            if (full_cmd != NULL)
            {
                argv[0] = full_cmd;
            }
            /* if not in PATH maybe user put the full path of the cmd  (/bin/ls) then check if this full path actually exists*/
            else if(access(argv[0], F_OK) != 0){
                printf("./shell: No such file or directory\n");
                continue;
            }
            pid = fork();
            if (pid == 0)
            {

                ex = execve(argv[0], argv, NULL);
                if (ex == -1)
                    printf("./shell: No such file or directory (inside fork)\n");
                exit(0);
            }

            if (pid != 0)
            {
                wait(NULL);
            }
        }
    }
    free(buffer);
    return 0;
}

#include "main.h"

void print_prompt(char *prompt)
{
    if (isatty(STDIN_FILENO))
    {
        size_t prompt_length = _strlen(prompt);
        write(STDOUT_FILENO, prompt, prompt_length);
    }
}

int is_exit_command(char *cmd)
{
	char exit_cmd[] = "exit";
	int i;

	for (i = 0; i < 4; i++)
	{
		if (cmd[i] != exit_cmd[i])
		{
			return (0);
		}
	}

	return (cmd[i] == '\0' || cmd[i] == ' ' || cmd[i] == '\n');
}

void tokenize_input(char *cmd, char *argv[])
{
	int i = 0;
	char *token = strtok(cmd, " \n"); /* Split input into tokens */

	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
}

void handle_command(char *argv[], char *cmd)
{
	pid_t pid;
	int status;

	if (is_exit_command(argv[0]))
	{
		free(cmd);
		exit(0);
	}

	/* Command exists in current directory */
	if (argv[0][0] != '/' && access(argv[0], F_OK) == 0)
	{
		append_cwd(argv[0]);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		free(cmd);
		exit(1);
	}

	if (pid != 0) /* Parent */
	{
		waitpid(pid, &status, 0);
	}
	else /* Child */
	{
		execve(argv[0], argv, NULL);
		perror(argv[0]);
	}
}

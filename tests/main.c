#include "main.h"

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

void append_cwd2(char *cmd)
{
	char cwd[MAX_PATH_LEN];
	int i, j;

	if (cmd[0] == '.') /* If the first character is '.', the path is already relative */
	{
		return;
	}

	getcwd(cwd, sizeof(cwd));

	for (i = 0; cwd[i] != '\0'; i++)
		;

	cwd[i++] = '/';

	for (j = 0; cmd[j] != '\0'; j++)
	{
		cwd[i + j] = cmd[j];
	}

	cwd[i + j] = '\0';

	for (i = 0; cwd[i] != '\0'; i++)
	{
		cmd[i] = cwd[i];
	}

	cmd[i] = '\0';
}

void append_cwd(char *cmd)
{
	char cwd[MAX_PATH_LEN];
	int i, j;

	getcwd(cwd, sizeof(cwd));

	for (i = 0; cwd[i] != '\0'; i++)
		;

	cwd[i++] = '/';

	for (j = 0; cmd[j] != '\0'; j++)
	{
		cwd[i + j] = cmd[j];
	}

	cwd[i + j] = '\0';

	for (i = 0; cwd[i] != '\0'; i++)
	{
		cmd[i] = cwd[i];
	}

	cmd[i] = '\0';
}

int main(void)
{
	char *cmd = NULL;
	char *argv[MAX_ARGS];
	char *token;
	size_t len = 0;
	ssize_t read;
	int status;
	pid_t pid;
	int i;

	while (1)
	{
		print_prompt("#cisfun$ ");

		read = getline(&cmd, &len, stdin);
		if (read == -1)
		{
			print_prompt("\n");
			free(cmd);
			exit(0);
		}

		i = 0;
		token = strtok(cmd, " \n"); /* Split input into tokens */
		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

		if (argv[0] == NULL)
		{ /* Ignore empty lines */
			continue;
		}

		if (is_exit_command(argv[0]))
		{
			free(cmd);
			exit(0);
		}

		if (argv[0][0] != '/' && access(argv[0], F_OK) == 0)
		{ /* Command exists in current directory */
			append_cwd2(argv[0]);
		}

		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			free(cmd);
			exit(1);
		}

		if (pid != 0)
		{ /* Parent */
			waitpid(pid, &status, 0);
		}
		else
		{ /* Child */
			execve(argv[0], argv, NULL);
			perror(argv[0]);
		}
	}

	return (0);
}


#include "main.h"

int main(void)
{
	char *cmd = NULL;
	char *argv[MAX_ARGS];
	size_t len = 0;
	ssize_t read;

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

		tokenize_input(cmd, argv);

		/* Ignore empty lines */
		if (argv[0] == NULL)
		{
			continue;
		}

		handle_command(argv, cmd);
	}

	return (0);
}


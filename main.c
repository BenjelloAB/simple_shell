#include "main.h"

/**
 * main - the entry point
 * @argc: no need for it now
 * @argv: arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int counter = 0;
	int status = 0;
	(void)argc;

	while (1)
	{
		line = read_command();
		if (line != NULL)
		{
			cmd = tokenize_command(line);
			counter++;

			if (cmd != NULL && !builtin_command(cmd, argv, counter, &status))
			{
				status = execute_command(cmd, argv, counter);
			}
		}
		else
		{
			print_prompt("\n");
			return (status);
		}
	}

	return (0);
}


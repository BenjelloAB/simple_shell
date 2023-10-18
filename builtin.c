#include "main.h"

/**
 * builtin_command - Check if a command is a built-in shell command
 * @cmd: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the original command.
 * @counter: An integer representing the command counter.
 * @status: A pointer to an integer representing the status of the shell.
 * Return: 1 if the command is a built-in and was executed successfully.
 */
int builtin_command(char **cmd, char **argv, int counter, int *status)
{
	int i;
	int num_commands;
	CommandMapping command_mappings[] = {
		{"env", print_env},
		{"exit", exit_shell},
	};

	num_commands = sizeof(command_mappings) / sizeof(CommandMapping);

	for (i = 0; i < num_commands; i++)
	{
		if (_strcmp(cmd[0], command_mappings[i].command) == 0)
		{
			command_mappings[i].func(cmd, status, argv, counter);
			return (1);
		}
	}

	return (0);
}

/**
 * exit_shell - Exit the shell with a specified exit code.
 * @cmd: An array of strings representing the command and its arguments.
 * @status: A pointer to an integer representing the status of the shell.
 * @argv: An array of strings representing the original command.
 * @counter: An integer representing the command counter.
 */

void exit_shell(char **cmd, int *status, char **argv, int counter)
{
	char *n;
	int exit_code = (*status);

	if (cmd[1])
	{
		if (!check_if_positive(cmd[1]))
		{
			n = _itoa(counter);

			write(2, argv[0], _strlen(argv[0]));
			write(2, ": ", 2);
			write(2, n, _strlen(n));
			write(2, ": exit: Illegal number: ", _strlen(": exit: Illegal number: "));
			write(2, cmd[1], _strlen(cmd[1]));
			write(2, "\n", 1);

			free(n);
			_free(cmd);
			(*status) = 2;
			return;
		}
		exit_code = _atoi(cmd[1]);
	}

	_free(cmd), exit(exit_code);
}

/**
 * print_env - Print the environment variables to the standard output.
 * @cmd: An array of strings representing the command and its arguments.
 * @status: A pointer to an integer representing the status of the shell.
 * @argv: An array of strings representing the original command
 * @counter: An integer representing the command counter.
 */

void print_env(char **cmd, int *status, char **argv, int counter)
{
	int i = 0;
	(void)status;
	(void)argv;
	(void)counter;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	_free(cmd);
	(*status) = 0;
}


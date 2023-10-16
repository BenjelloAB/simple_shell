#include "main.h"

/**
 * execute_command - Execute a command with arguments.
 * @cmd: An array of strings representing the command
 * @argv: An array of strings representing the original command
 * @counter: An integer representing the command counter.
 * Return: The exit status of the executed command.
 */

int execute_command(char **cmd, char **argv, int counter)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = find_executable(cmd[0]);
	if (!full_cmd)
	{
		print_error(argv[0], cmd[0], counter);
		_free(cmd);
		return (127);
	}

	child = fork();

	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			_free(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(full_cmd);
		full_cmd = NULL;
		_free(cmd);
	}
	return (WEXITSTATUS(status));
}

/**
 * read_command - Read a command from standard input.
 * Description: This function reads a command from standard input
 * the user with "#cisfun$", and returns the input
 * string after removing leading/trailing whitespace
 * Return: A dynamically allocated string containing the input command.
 */
char *read_command(void)
{
	char *hash_pos;
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	print_prompt("#cisfun$ ");

	n = getline(&line, &len, stdin);

	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	line[n - 1] = '\0';

	_trim(line);

	hash_pos = _strchr(line, '#');
	if (hash_pos != NULL)
	{
		*hash_pos = '\0';
	}
	_trim(line);

	return (line);
}

/**
 * tokenize_command - Tokenize a command line into an array of tokens.
 * @line: A string representing the command line to be tokenized.
 * Return: An array of strings representing the tokens.
 */

char **tokenize_command(char *line)
{
	int i = 0, len = 0;
	char *temp_line = NULL, *token = NULL;
	char **cmd = NULL;

	if (line == NULL)
		return (NULL);

	temp_line = strdup(line);
	token = _strtok(temp_line, TOKEN_DELIMITER);

	if (token == NULL)
	{
		free(line);
		free(temp_line);
		return (NULL);
	}

	while (token != NULL)
	{
		len++;
		token = _strtok(NULL, TOKEN_DELIMITER);
	}
	free(temp_line);
	cmd = malloc(sizeof(char *) * (len + 1));
	if (!cmd)
	{
		free(line);
		return (NULL);
	}

	token = _strtok(line, TOKEN_DELIMITER);
	while (token)
	{
		cmd[i] = strdup(token);
		i++;
		token = _strtok(NULL, TOKEN_DELIMITER);
	}

	free(line), cmd[i] = NULL;
	return (cmd);
}


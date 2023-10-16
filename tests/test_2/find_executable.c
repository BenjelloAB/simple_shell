#include "main.h"

/**
 * find_executable - Find the executable path for a given command.
 * @cmd: A string representing the command to find the executable for.
 * Return: A dynamically allocated string containing the full executable path
 */

char *find_executable(char *cmd)
{
	char *full_path, *dir, *path_env;
	int i;
	size_t len;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));

			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (path_env);
	dir = _strtok(path_env, ":");
	while (dir)
	{
		len = _strlen(dir) + _strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path)
		{
			_strcpy(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, cmd);

			if (stat(full_path, &st) == 0)
			{
				free_and_null(path_env);
				return (full_path);
			}
			free_and_null(full_path);
			dir = _strtok(NULL, ":");
		}
	}
	free_and_null(path_env);
	return (NULL);
}


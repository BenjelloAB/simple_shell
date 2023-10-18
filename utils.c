#include "main.h"

/**
 * _free - Frees memory allocated for a dynamically allocated array of strings
 * @arr: The array of strings to be freed
 */
void _free(char **arr)
{
	int i = 0;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

/**
 * _getenv - Retrieves the value of a specific environment variable
 * @var_name: The name of the environment variable to retrieve
 * Return: the environment variable or null
 */
char *_getenv(char *var_name)
{
	int i;
	char *tmp;
	char *value;
	char *key;
	char *env;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		/* split by = */
		key = _strtok(tmp, "=");
		if (_strcmp(key, var_name) == 0)
		{
			value = _strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free_and_null(tmp);
	}
	return (NULL);
}

/**
 * free_and_null - Free the memory of a pointer and set it to NULL.
 * @path: A pointer to the memory to be freed and set to NULL.
 */

void free_and_null(char *path)
{
	free(path);
	path = NULL;
}

/**
 * check_if_positive - Check if a string represents a positive integer.
 * @str: A string to be checked.
 * Return: 1 if the string represents a positive integer, 0 otherwise.
 */

int check_if_positive(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}


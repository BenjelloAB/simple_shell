#include "main.h"

/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: A pointer to the string to search.
 * @c: The character to search for.
 * Return: A pointer to the first occurrence of the character
 */

char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _trim - Trim leading and trailing whitespace from a string.
 * @str: A pointer to the string to be trimmed.
 * Return: void
 */

void _trim(char *str)
{
	int i;
	int j;
	int len = _strlen(str);

	for (i = 0; i < len && (str[i] == ' ' || str[i] == '\t'); i++)
		;

	for (j = 0; i < len; i++, j++)
		str[j] = str[i];

	str[j] = '\0';

	for (i = _strlen(str) - 1; i > 0 && (str[i] == ' ' || str[i] == '\t'); i--)
		str[i] = '\0';
}


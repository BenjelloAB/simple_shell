#include "main.h"

/**
 * _strlen - Custom strlen to get the length of a string
 * Description: function to get the length of a string
 * @str: the string
 * Return: number of characters
 */

size_t _strlen(char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - Custom strcpy to copy a string
 * @dest: the dest string
 * @src: the src string
 * Return: pointer.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcat - Custom strcat to concatenate strings.
 * @dest: the dest buffer
 * @src: the src buffer
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcmp - Custom strcmp to compare 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: negative or positive or zero.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strdup - Custom strdup to make a copy of a string
 * @str: the string
 * Return: pointer
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}


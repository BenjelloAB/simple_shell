#include "main.h"

/**
 * is_delim - check if a character is a delimeter
 * Description: function to check if a character is a delimeter
 * @c: the character
 * @delim: the delimeter to checker against
 * Return: boolean
 */

unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - custom implement of strtok
 * Description: custom strtok
 * @srcString: the string
 * @delim: the delimeter
 * Return: the string or null
 */

char *_strtok(char *srcString, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!srcString)
		srcString = backup_string;
	if (!srcString)
		return (NULL);
	while (1)
	{
		if (is_delim(*srcString, delim))
		{
			srcString++;
			continue;
		}

		if (*srcString == '\0')
		{
			return (NULL);
		}
		break;
	}
	ret = srcString;

	while (1)
	{
		if (*srcString == '\0')
		{
			backup_string = srcString;
			return (ret);
		}
		if (is_delim(*srcString, delim))
		{
			*srcString = '\0';
			backup_string = srcString + 1;
			return (ret);
		}
		srcString++;
	}
}


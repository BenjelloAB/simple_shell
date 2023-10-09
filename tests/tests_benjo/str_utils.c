#include "main.h"
/**/
int _strlen(char *str)
{
    int i = 0, len = 0;

	while (str[i])
    	{
		len++;
		i++;
	}
	return (len);
}
/**/
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}
/*
*
*
*
*/
char *_strcat(char *dest, char *src)
{
  int i = 0;
int len = 0;  
    if (!dest | !src)
        return NULL;
  
    len = _strlen(dest);
    while (src[i])
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}

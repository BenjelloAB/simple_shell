#include "main.h"

/**
 * _strlen - get the length of a string
 * @s: the string
 * Return: number of characters
 */

size_t _strlen(char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

#include <unistd.h>

int _strlen(char *str)
{
    int i = 0, len = 0;

    while(str[i])
    {
        len++;
        i++;
    }
    return (len);
}


#include "main.h"

size_t _strlen(char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void print_prompt(char *prompt)
{
    if (isatty(STDIN_FILENO))
    {
        size_t prompt_length = _strlen(prompt);
        write(STDOUT_FILENO, prompt, prompt_length);
    }
}

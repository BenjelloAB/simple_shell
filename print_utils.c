#include "main.h"

/**
 * print_prompt - Prints a prompt to the standard output if it's a terminal.
 * @prompt: The prompt to be printed
 * Return: void
 */
void print_prompt(char *prompt)
{
	if (isatty(STDIN_FILENO))
	{
		size_t prompt_length = _strlen(prompt);

		write(STDOUT_FILENO, prompt, prompt_length);
	}
}

/**
 * print_error - prints an error message with the provided details.
 * @name: The file name associated with the error.
 * @buffer: The specific buffer content
 * @counter: An integer counter associated with the error
 * Return: void
 */
void print_error(char *name, char *buffer, int counter)
{
	char *n = _itoa(counter);

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, n, _strlen(n));
	write(2, ": ", 2);
	write(2, buffer, _strlen(buffer));
	write(2, ": not found\n", 12);

	free(n);
}

/**
 * _itoa - Converts an integer to a null-terminated string
 * @n: The integer to be converted
 * Return: A dynamically allocated string representing the integer.
 */
char *_itoa(int n)
{
	char base[] = "0123456789";
	char *newstr;
	unsigned int len = 0;
	int number = n;

	for (len = 0; n > 0; len++)
	{
		n = n / 10;
	}

	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	newstr[len] = '\0';
	do {
		newstr[--len] = base[number % 10];
		number /= 10;
	} while (number != 0);
	return (newstr);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: A string representing the integer to convert.
 * Return: The integer value converted from the string.
 */

int _atoi(char *str)
{
	int res = 0;
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';

	return (res);
}


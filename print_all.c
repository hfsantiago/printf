#include "holberton.h"

/**
 * print_all - print char.
 * @str: string.
 *
 * Return: string length.
 */

int print_all(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);

	return (i);
}

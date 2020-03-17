#include "holberton.h"
#include <string.h>
/**
 * _strlen - length of one string
 * @s: length of string.
 * Return: return an integer called count.
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;

	return (i);
}

#include "holberton.h"
/**
 *s_printer - the main array of struct char*
 *@s: the character of char of main array
 *
 *Return: return length of string.
 */
int s_printer(va_list s)
{
	char *temp;
	int i;

	temp = va_arg(s, char *);
	if (temp == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');

		return (6);
	}
	else
	{
		for (i = 0; temp[i] != 0; i++)
		{
			_putchar(temp[i]);
		}
	}
	return (i);
}

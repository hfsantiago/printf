#include "holberton.h"
/**
 *c_printer - the main function of char C.
 *@c: the character of main array.
 *
 *Return: always 1.
 */
int c_printer(va_list c)
{
	int c_ascii;

	c_ascii = va_arg(c, int);
	_putchar(c_ascii);
	return (1);
}

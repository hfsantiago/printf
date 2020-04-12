#include "holberton.h"

/**
 * i_printer - Print a number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal
 **/
int i_printer(va_list list)
{
	char *buff;
	int size;

	buff = itoa(va_arg(list, int), 10);

	size = print_all((buff != NULL) ? buff : "NULL");

	return (size);

}

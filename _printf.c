#include "holberton.h"
/**
 * _printf - this print.
 * @format: contain set struct
 *
 * Return: return a character of strings.
 */
int _printf(const char *format, ...)
{
	int length; /*this variable is for measure of length of string*/
	int i; /*first loop for to know length of format_string*/
	int j; /*second loop for number of format_prints*/
	int numb_char; /*number of characters that it's going to prints*/
	int number_prints;
	va_list prmt;

	va_start(prmt, format);
	format_print form[] = {
		{"c", c_printer},
		{"s", s_printer}
	};

	if (format == NULL)
	{
		return (-1);
	}

	length = _strlen(format);
	number_prints = sizeof(form) / sizeof(form[0]);
	for (i = 0; i < length; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			if (format[i + 1] == '%')
			{
				i += 1;
				_putchar('%');
				numb_char += 1;
				continue;
			}
			for (j = 0; j < number_prints; j++)
			{
				if (format[i + 1] == *(form[j].type))
				{
					numb_char = form[j].funct(prmt) + numb_char;
					i = i + 1;
					break;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			numb_char = numb_char + 1;
		}
	}
	return (numb_char);
}

#include "holberton.h"
/**
 *selector - pointer to selector.
 *@c: char c.
 *
 *Return: always NULL
 */

int (*selector(char c)) (va_list)
{
	int n_formats, i;
	format_print form[] = {
		{"c", c_printer},
		{"s", s_printer},
		{"d", i_printer},
		{"i", i_printer}
	};

	n_formats = sizeof(form) / sizeof(form[0]);
	for (i = 0; i < n_formats; i++)
	{
		if (c == *(form[i].type))
			return (form[i].funct);
	}

	return (NULL);
}
/**
 *_printf - proptotype of print.
 *@fmt: pointer to format that return a integer
 *
 *Return: return size of a string.
 */

int _printf(const char *fmt, ...)
{
	int i, size;
	va_list args;

	va_start(args, fmt);

	if (fmt == NULL)
		return (-1);

	for (i = size = 0; fmt[i] != 0; i++)
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 0)
				return (-1);

			if (fmt[i] == '%')
			{
				_putchar('%'), size++;
				continue;
			}

			if (selector(fmt[i]) ==  NULL)
			{
				_putchar('%'), _putchar(fmt[i]);
				size += 2;
			}
			else
			{
				size += selector(fmt[i])(args);
			}
		}
		else
		{
			_putchar(fmt[i]), size++;
		}
	}

	return (size);
}

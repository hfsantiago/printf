#include "holberton.h"
/**
 *controller - handle a controller a struct
 *@str: pointer an a string.
 *@i:position of array.
 *
 *Return: always 0
 */

int controller(const char *str, int *i)
{
	*i = *i + 1;
	if (str[*i] == 0)
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	return (0);
}

/**
 * _printf - this print.
 * @format: contain set struct
 *
 * Return: return a character of strings.
 */
int _printf(const char *format, ...)
{
	int i, j, numb_char, aux;
	va_list prmt;
	format_print form[] = {
		{"c", c_printer},
		{"s", s_printer}
	};

	va_start(prmt, format);
	if (format == NULL)
		return (-1);
	for (i = aux = numb_char = 0; format[i] != 0; i++)
	{
		if (format[i] == '%')
		{
			aux = controller(format, &i);
			if (aux == -1)
				return (-1);
			if (aux == 1)
			{
				numb_char += aux;
				continue;
			}
			for (j = 0; j < 2; j++)
			{
				if (format[i + 1] == *(form[j].type))
				{
					numb_char = form[j].funct(prmt) + numb_char, i = i + 1;
					break;
				}
			}
			_putchar('%'), numb_char += 2;
			_putchar(format[i]);
		}
		else
		{
			_putchar(format[i]);
			numb_char = numb_char + 1;
		}
	}
	return (numb_char);
}

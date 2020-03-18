#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>
#include <stdlib.h>
/**
 *_printf - prototype our printf
 *@format: save the character input in the string variable.
 *Return: strings length
 **/
int _printf(const char *format, ...);
/**
 * struct _format_print - this is our strcuture for to call
 * the different printer
 * @type: type will be print
 * @funct: function toi print
 */
typedef struct _format_print
{
	char *type;
	int (*funct)(va_list);
} format_print;

int c_printer(va_list);
int s_printer(va_list);
int i_printer(va_list);
int _strlen(const char *);
int _putchar(char c);

char *itoa(long int number, int base);
int print_all(char *);

#endif

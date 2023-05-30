#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned i;
	unsigned count = 0;
	va_list list;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
					int c;
					c = va_arg(list, int);
					write(1, &c, 1);
					count++;
					break;
					}
				case 's':
					{
					char *s = va_arg(list, char *);
					size_t len = strlen(s);
					write(1, s, len);
					count += len;
					break;
					}
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(list);

	return (count);
}

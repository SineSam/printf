#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
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
					_putchar("%s%c", va_arg(list, format));
					count++;
					break;
				case 's':

					_putchar("%s%s", va_arg(list, format));
					count++;
					break;
				case '%':
					_putchar('%');
					count++;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
				count++;
		}
	}
	va_end(list);
	return (count);
}

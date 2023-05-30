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
	unsigned int i, count = 0;
	char c;
	va_list list;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c')
				c = va_arg(list, int);
				count += write(1, &c, 1);
			else if (*format == 's')
				count += write(1, va_arg(list, char *), strlen(va_arg(list, char *)));
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int), len = 0;
				char num_str[20];

				if (num < 0 && (++count))
					write(1, "-", 1);
				do {
					num_str[len++] = '0' + ((num < 0 ? -num : num) % 10);
				} while (num /= 10);
				while (len--)
				write(1, &num_str[len], 1), count += 2;
				count++;
			}
			else if (*format == '%')
				write(1, "%", 1), count++;
			else
				write(1, "%", 1), write(1, format, 1), count += 2;
		}
		else
			write(1, format, 1), count++;
		format++;
	}
	va_end(list);
	return (count);
}

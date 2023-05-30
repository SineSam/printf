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
				case 'd':
				case 'i':
					{
						int num = va_arg(list, int);
						int num_abs = (num < 0) ? -num: num;
						char num_str[20];
						int len = 0;
						int i;

						if (num < 0)
						{
							write(1, "-", 1);
							count++;
						}
						do
						{
							num_str[len++] = '0' + (num_abs % 10);
							num_abs /= 10;
						}
						while (num_abs != 0);

						for (i = len - 1; i >= 0; i--)
						{
							write(1, &num_str[i], 1);
							count++;
						}
						break;
				case '%':
					{
						write(1, "%", 1);
						count++;
						break;
					}
				default:
					{
					write(1, "%", 1);
					count++;
					write(1, format, 1);
					count++;
					break;
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

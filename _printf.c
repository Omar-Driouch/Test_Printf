#include "main.h"
/**
 * _printf - Custom implementation of the printf function
 * @format: A pointer to a null-terminated format string.
 * Return: The total number of characters printed, or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char spec[] = {'i', 'd', 'c', 's', 'b', 'o', 'u', 'x', 'X', 'S', 'p', '\0'};
	int total_written = 0, i = 0, j = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (j = 0; spec[j] != '\0'; j++)
			{
				if (format[i + 1] == spec[j])
				{
					total_written += get_right_func(format + i + 1)(args);
					i += 2;
					break;
				}
			}
			if (spec[j] == '\0')
			{
				if (format[i + 1] == '%')
					i++;
				goto print_me;
			}
		}
		else
		{
print_me:
			total_written += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (total_written);
}

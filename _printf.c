#include "main.h"
/**
 * _printf - Custom implementation of the printf function
 * @format: A pointer to a null-terminated format string.
 * Return: The total number of characters printed, or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char spec[6] = {'i', 'd', 'c', 's', 'b', 'o'};
	char ignore[4] = {'%', '!', 'K', 'r'};
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
			for (j = 0; j < 6; j++)
			{
				if (format[i + 1] == spec[j])
				{
					total_written += get_right_func(format + i + 1)(args);
					i += 2;
					break;
				}
				else if (ignore[j] == format[i + 1] && j < 4)
				{
					total_written += _putchar(format[i]);
					if (ignore[j] != '%')
						total_written += _putchar(ignore[j]);
					i += 2;
				}
			}
		}
		else
		{
			total_written += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (total_written);
}

#include "main.h"

/**
 * _printf - Print formatted output according to the format specifier
 * @format: A pointer to a format string containing the specifiers
 * @...: Additional arguments corresponding to the format specifiers
 *
 * Return: The number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	char Specifiers[] = {'c', 's', 'd', 'i', 'u', 'o', 'b', 'x', 'X', '\0'};
	int i, j, len = 0;
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			for (j = 0; Specifiers[j] != '\0'; j++)
			{
				if (format[i + 1] == Specifiers[j])
				{
					len += get_right_func(format + i + 1)(args);
					i += 2;
					break;
				}
			}
			if (Specifiers[j] == '\0')
			{
				if (format[i + 1] == '%')
					i++;
				goto print_me;
			}
		}
		else
		{
print_me:
			len += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

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
	/* This number '4' will be changed when we add more specifiers */
	char Specifiers[5] = {'c', 's', 'd', 'i', 'o'};
	int i, j, len = 0;
	va_list args;

	/* Return -1 if format is NULL */
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		/* if format[i] == '%' then check the next character */
		is_percent:
		if (format[i] == '%')
		{
			for (j = 0; j < 5; j++)
			{
				if (format[i + 1] == Specifiers[j])
				{
					len += get_formatting_func(format[++i])(args);
					i++;
					goto is_percent;
				}
				else if (format[i + 1] == '%')
				{
					len += _putchar(format[++i]);
					i++;
					goto is_percent;
				}
			}
		}

		len += _putchar(format[i]);
	}

	va_end(args);
	return (len);
}

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
	char Specifiers[4] = {'c', 's', 'd', 'i'};
	int i, j;
	va_list args;

	/* Return -1 if format is NULL */
	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '0'; i++)
	{
		/* if format[i] == '%' then check the next character */
		for (j = 0; format[i] == '%' && j < 4; j++)
		{
			if (format[i + 1] == Specifiers[j])
			{
				i++;
				get_formatting_func(format[i])(args);
			}
			else if (format[i] == '%')
			{
				i++;
				_putchar(format[i]);
			}
		}

		_putchar(format[i]);
	}

	va_end(args);
}

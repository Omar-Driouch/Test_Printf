#include "main.h"

/**
 * get_formatting_func - Gets the corresponding function
 * for the given specifier
 * @c: The given specifier
 *
 * Return: The the corresponding function for the sepicifer @c
 */
int (*get_formatting_func(char *c))(va_list)
{
	/* if format[i] == '%' then check the next character */
	formatter_t Formatter[4] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (Formatter[i].spec == c)
			return (Formatter[i].func);
	}
}

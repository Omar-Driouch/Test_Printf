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
	formatter_t Formatter = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', print_b},
		{NULL, NULL}
	};

	/* Rest of code that returns the correct function will be soon */
}

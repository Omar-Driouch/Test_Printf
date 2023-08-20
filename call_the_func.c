#include "main.h"

/**
 * get_right_func - function that selects the correct function
 * @s: pointer to format specifier
 * Return: pointer to the function that takes va_list as its param
 */

int (*get_right_func(const char *s))(va_list)
{
	formatter_t Spe_func[] = {
		{'c', printf_c},
		{'s', printf_s},
		{'i', printf_i},
		{'d', printf_i},
		{'o', printf_o},
		{'u', printf_u},
		{'b', printf_b},
		{'x', printf_x},
		{'X', printf_X},
		{0, NULL}};
	int i = 0;

	while (Spe_func[i].spec != 0)
	{
		if (Spe_func[i].spec == *s)
			return ((int (*)(va_list))Spe_func[i].func);
		i++;
	}

	return (NULL);
}

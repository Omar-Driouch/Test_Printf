#include <main.h>



/**
 * get_right_func - function that selects the correct function
 * @s: pointer to format specifier
 * Return: pointer to call the right function that takes va_list as its param
*/
int (*get_right_func(char *s))(va_list)
{
	formatter_t Spe_func[] = {
		{"c", _putchar},
		{"s", printf_string},
		{NULL, NULL}};
	int i = 0;

	while (i < 5)
	{
		if (strcmp(Spe_func[i].spec, s) == 0)
			return (Spe_func[i].func);
		i++;
	}

	return (NULL);
}
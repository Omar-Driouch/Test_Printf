#include "main.h"
/**
 * _printf - Custom implementation of the printf function
 * @f: A pointer to a null-terminated f string.
 * Return: The total number of characters printed, or -1 if an error occurs.
 */
int _printf(const char *f, ...)
{
	va_list args;
	char spec[] = {'i', 'd', 'c', 's', 'b', 'o', 'u', 'x', 'X', 'S', 'p',
				   'r', '#', '+', ' ', 'R', 'l', 'h', '*', '0', '\0'};
	int total_written = 0, i = 0, j = 0;

	if (!f || ((f[0] == '%' && !f[1]) || (f[0] == '%' && f[1] == ' ' && !f[2])))
		return (-1);
	va_start(args, f);
	while (f[i] != '\0')
	{
		if (f[i] == '%' && f[i + 1] != '\0')
		{
			for (j = 0; spec[j] != '\0'; j++)
			{
				if (f[i + 1] == spec[j] || _isdig(f[i + 1]))
				{
					if (f[i + 1] == '#' || f[i + 1] == ' ' || f[i + 1] == '+' ||
					f[i + 1] == 'l' || f[i + 1] == 'h' || f[i + 1] == '*' || _isdig(f[i + 1]))
						total_written += get_flag(f, &i, args);
					else
						total_written += get_right_func(f + i + 1)(args);
					i += 2;
					break;
				}
			}
			if (spec[j] == '\0')
			{
				if (f[i + 1] == '%')
					i++;
				goto print_me;
			}
		}
		else
		{
print_me:
			total_written += _putchar(f[i++]);
		}
	}
	va_end(args);
	return (total_written);
}

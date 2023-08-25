#include "main.h"


/**
 * Handle_digits - format specifier in a formatted string.
 *
 * @s:     The formatted string.
 * @i:     Pointer to the current position in the string.
 * @ar_ls: Variable argument list.
 *
 * Return: Number of characters written.
 */

int Handle_digits(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, n = *i, num, le = 0, k, end = s[n + 1], isUpp = 0;
	va_list copy;
	char *stre;

	va_copy(copy, ar_ls);
	num = va_arg(copy, int);
	while (_isdig(s[n + 1]))
	{
		if (s[n + 2] == 'd' || s[n + 2] == 'i')
		{
			for (k = 0; k < end - 48 - _lentofInt(num); k++)
				le += _putchar(' ');
			le = customFunction_flag(num, s, n, le, ar_ls);
		}
		else if (s[n + 2] == 'u')
		{
			for (k = 0; k < end - 48 - _lentofInt(num); k++)
				le += _putchar(' ');
			le += printf_Lu(ar_ls);
		}
		else if (s[n + 2] == 'o')
		{
			for (k = 0; k < end - 48 - _lentofInt(num); k++)
				le += _putchar(' ');
			le += print_base(ar_ls, 8, 0);
		}
		else if (s[n + 2] == 'x' || s[n + 2] == 'X')
		{
			stre =  _ConverTobase((long)num, 16, isUpp);
			if (s[n + 2] == 'X')
				isUpp = 1;
			for (k = 0; k < end - 48 - _strlen(stre); k++)
				le += _putchar(' ');
			le += print_base(ar_ls, 16, isUpp);
		}
		n++;
	}
	n = (le == 0) ? keepI : n;
	*i = n;
	return (le);
}

/**
 * _isdig - checks if parameter is a number between 0 to 9.
 * @c: input number.
 * Return: 1 if is a number (0 to 9), 0 in other case.
 */

int _isdig(int c)
{
	return (c >= '0' && c <= '9');
}

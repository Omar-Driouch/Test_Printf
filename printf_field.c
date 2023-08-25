#include "main.h"

/**
 * Handle_digits_Field - format specifier in a formatted string.
 *
 * @s:     The formatted string.
 * @i:     Pointer to the current position in the string.
 * @ar_ls: Variable argument list.
 *
 * Return: Number of characters written.
 */

int Handle_digits_Field(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, n = *i, num, le = 0, k, end = s[n + 1], isU = 0;
	va_list copy;

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
			if (s[n + 2] == 'X')
				isU = 1;
			for (k = 0; k < end - 48 - _strlen(_ConverTobase((long)num, 16, isU)); k++)
				le += _putchar(' ');
			le += print_base(ar_ls, 16, isU);
		}
		n++;
	}
	n = (le == 0) ? keepI : n;
	*i = n;
	if (le == 0)
		le = Handle_Char_Field(s, i, ar_ls);
	return (le);
}

/**
 * Handle_Char_Field - format specifier in a formatted string.
 *
 * @s:     The formatted string.
 * @i:     Pointer to the current position in the string.
 * @ar_ls: Variable argument list.
 *
 * Return: Number of characters written.
 */

int Handle_Char_Field(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, n = *i, le = 0, k, end = s[n + 1];
	va_list charr;
	char *str;

	va_copy(charr, ar_ls);
	str = va_arg(charr, char *);

	while (_isdig(s[n + 1]))
	{
		if (s[n + 2] == 'c')
		{
			for (k = 0; k < end - 48 - 1; k++)
				le += _putchar(' ');
			le += printf_c(ar_ls);
		}
		if (s[n + 2] == 's')
		{
			for (k = 0; k < end - 48 - _strlen(str); k++)
				le += _putchar(' ');
			le += printf_s(ar_ls);
		}
		n++;
	}

	n = (le == 0) ? keepI : n;
	*i = n;
	if (le == 0)
		le = Handle_Star_Field(s, i, ar_ls);
	return (le);
}

/**
 * Handle_Star_Field - Process formatted numerical output with variable-width
 *                     padding
 *
 * This function processes a format string and variable arguments list to print
 * formatted numerical data with variable-width padding based on the format
 * specifiers in the input string.
 *
 * @s:      The format string containing format specifiers.
 * @i:      A pointer to an integer representing the current position in s.
 * @ar_ls:  A variable argument list.
 *
 * Return:       The number of characters written.
 */

int Handle_Star_Field(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, num, lent, n = *i, le = 0, k;
	va_list cop, rest;

	va_copy(cop, ar_ls);
	va_copy(rest, ar_ls);
	/* first = va_arg(cop, int); */
	num = va_arg(ar_ls, int);
	lent = va_arg(ar_ls, unsigned long);
	while (s[n + 1] == '*')
	{
		if (s[n + 2] == 'd' || s[n + 2] == 'i')
		{
			for (k = 0; k < num - _lentofInt(lent); k++)
				le += _putchar(' ');
			le += print_number(lent);
		}
		if (s[n + 2] == 'u')
		{
			for (k = 0; k < num - _lentofInt(lent); k++)
				le += _putchar(' ');
			le += print_number(lent);
		}
		n++;
	}
	n = (le == 0) ? keepI : n;
	*i = n;
	(le == 0) ? le = Handle_char_with_star(s, i, rest) : le;
	return (le);
}

/**
 * Handle_char_with_star - Process formatted character and string output
 * with variable-width padding
 *
 * This function processes a format string and variable arguments
 * list to print
 * formatted character or string data with variable-width padding.
 *
 * @s:      The format string containing format specifiers.
 * @i:      A pointer to an integer representing the current position in s.
 * @ar_ls:  A variable argument list.
 *
 * Return:       The number of characters written.
 */

int Handle_char_with_star(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, num, n = *i, le = 0, k, first;
	va_list cop, reset;
	char *second;

	va_copy(cop, ar_ls);
	va_copy(reset, ar_ls);
	first = va_arg(cop, int);
	second = va_arg(cop, char *);
	num = va_arg(ar_ls, int);
	(void)num;
	while (s[n + 1] == '*')
	{
		if (s[n + 2] == 'c')
		{
			for (k = 0; k < first - 1; k++)
				le += _putchar(' ');
			le += printf_c(ar_ls);
		}
		else if (s[n + 2] == 's')
		{
			for (k = 0; k < first - _strlen(second); k++)
				le += _putchar(' ');
			le += printf_s(ar_ls);
		}
		else
		{
			break;
		}
		n++;
	}
	n = (le == 0) ? keepI : n;
	*i = n;
	(le == 0) ? le = Handle_Star_Field_2(s, i, reset) : le;
	return (le);
}

/**
 * Handle_Star_Field_2 - Process formatted output with variable-width padding
 *
 * This function processes a format string and variable arguments list similar
 * to printf, but with additional support for variable-width padding.
 *
 * @s:    The format string containing format specifiers.
 * @i:    A pointer to an integer representing the current position in s.
 * @ar_ls: A variable argument list.
 *
 * Return:     The number of characters written.
 */

int Handle_Star_Field_2(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, num, lent, n = *i, le = 0, k, isU = 0, first;
	va_list cop, rest;

	va_copy(cop, ar_ls);
	va_copy(rest, ar_ls);
	first = va_arg(cop, int);
	num = va_arg(ar_ls, int);
	lent = va_arg(ar_ls, unsigned long);
	while (s[n + 1] == '*')
	{
		if (s[n + 2] == 'o')
		{
			for (k = 0; k < num - _lentofInt(lent); k++)
				le += _putchar(' ');
			le += printf_o(cop);
		}
		else if (s[n + 2] == 'x' || s[n + 2] == 'X')
		{
			if (s[n + 2] == 'X')
				isU = 1;
			for (k = 0; k < num - _strlen(_ConverTobase((long)lent, 16, isU)); k++)
				le += _putchar(' ');
			le += printf_x_or_X(lent, isU);
		}
		n++;
	}
	n = (le == 0 && first != 0) ? keepI : n;
	*i = n;

	return (le);
}

#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - Prints a number
 * @num: Number to print
 *
 * Return: Length of the printed number
 */
int print_number(long num)
{
	long len = 0;

	if (num < 0)
	{
		num = -num;
		len += _putchar('-');
	}

	if (num >= 10)
		len += print_number(num / 10);

	len += _putchar(num % 10 + '0');

	return (len);
}

/**
 * printf_x_or_X - Converts and prints a decimal to its hex value
 * @num: Decimal number to convert
 * @is_lower: Decides to print the hex either in upper or lower case
 *
 * Return: Length of the printed number
 */
int printf_x_or_X(unsigned int num, int is_lower)
{
	int i, len = 0;
	int hex_digit;
	char char_base = 'A';

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	if (is_lower)
		char_base = 'a';

	for (i = 28; i >= 0; i -= 4)
	{
		/* Shifting and using Bitwise opearnd to take the Hex value */
		hex_digit = (num >> i) & 0xF;

		if (hex_digit > 0 || len > 0)
		{
			if (hex_digit < 10)
				len += _putchar(hex_digit + '0');
			else
				len += _putchar(hex_digit - 10 + char_base);
		}
	}
	return (len);
}

/**
 * customFunction_flag - Custom function for handling printf specifiers.
 *
 * This function takes arguments `num`, `s`, `n`, `le`, and a variable
 * argument list `ls`. It checks `s` for specific specifiers ('x', 'X', 'o')
 * and updates `le` accordingly, returning the updated `le`.
 *
 * @num: Integer affecting the function's behavior.
 * @s: Format specifier string.
 * @n: Index for parsing `s`.
 * @le: Current length.
 * @ls: Variable argument list for printf-like functionality.
 *
 * Return: Updated length .
 */

int customFunction_flag(int num, const char *s, int n, int le, va_list ls)
{
	if (s[n + 2] == 'x')
	{
		(num == 0) ? (le -= 2) : (s[n + 2] == 'x' && s[n + 1] != ' ' &&
		s[n + 1] != '+') ? _printf("0x") : 0;
		le = 2 + le + printf_x(ls);
	}
	if (s[n + 2] == 'X')
	{
		(num == 0) ? (le -= 2) : (s[n + 2] == 'X' && s[n + 1] != ' ' &&
		s[n + 1] != '+') ? _printf("0X") : 0;
		le = 2 + le + printf_X(ls);
	}
	if (s[n + 2] == 'o')
	{
		(num == 0) ? (le -= 1) : (s[n + 2] == 'o' && s[n + 1] != ' ' &&
		s[n + 1] != '+') ? _putchar('0') : 0;
		le = 2 + le + printf_o(ls) - 1;
	}
	if (s[n + 2] == 'd' || s[n + 2] == 'i')
	{
		if (s[n + 1] == '+' && num >= 0)
			le += _putchar('+');
		else if (s[n + 1] == ' ' && num >= 0)
			le += (s[n] == '%') ? _putchar(s[n + 1]) : _putchar(s[n]);
		le += printf_i(ls);
	}

	return (le);
}

/**
 * print_largeNum - Prints a large unsigned long number
 * @num: The number to be printed
 *
 * This function prints a large unsigned long number to the standard output.
 * If the number is negative, it is converted to a positive number and a minus
 * sign is printed before it. The function recursively divides the number by 10
 * to print each digit individually.
 *
 * Return: The number of characters printed.
 */

int print_largeNum(unsigned long num)
{
	unsigned long len = 0;

	if ((long)num < 0)
	{
		num = -num;
		len += _putchar('-');
	}

	if (num >= 10)
		len += print_number(num / 10);

	len += _putchar(num % 10 + '0');

	return (len);
}

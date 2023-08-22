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


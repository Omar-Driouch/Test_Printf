#include "main.h"

/**
 * printf_b - Custom printf conversion for binary integer printing.
 *
 * Takes a va_list with an integer, converts it to binary
 * and prints the reversed binary string.
 *
 * @b:ls - va_list with the integer to convert and print.
 *
 * Return:Result of the print_rev function, indicating printed character count
 */

int printf_b(va_list b)
{
	unsigned int dec = va_arg(b, int);
	int i = 31, lenght = 0;
	int non_zero_found = 0;

	while (i >= 0)
	{
		int qinae = (1 << i);

		if (dec & qinae)
		{
			_putchar('1');
			non_zero_found = 1;
		}
		else if (non_zero_found || i == 0)
		{
			_putchar('0');
		}
		lenght++;
		i--;
	}

	return (lenght);
}

/**
 * printf_o - Prints a number in base 8 (octal)
 * @o: Number to print in base 8
 *
 * Return: Length of the printed number
 */
int printf_o(va_list o)
{
	long dec = va_arg(o, int);
	long i, oct = 0;
	const long UNSIGNED_MAX = 4294967296;

	if (dec < 0)
		dec += UNSIGNED_MAX;

	for (i = 1; dec != 0; i *= 10)
	{
		oct += (dec % 8) * i;
		dec /= 8;
	}

	return (print_number(oct));
}

/**
 * printf_i - Custom printf function to print an integer.
 * @i: va_list containing the argument to be printed.
 *
 * This function is used as part of a custom printf implementation
 * to print an integer
 * argument. It handles both positive and negative integers, calculates
 * the number of
 * digits in the integer, and prints each digit separately.
 *
 * Return: The number of characters printed.
 */
int printf_i(va_list i)
{
	long num = va_arg(i, int);

	return (print_number(num));
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
 * printf_u - convert an input argument into unsigned int
 * @u: the input args
 *
 * Return: the count  of printed numbers
 */

int printf_u(va_list u)
{
	long num = va_arg(u, int);
	const long UNSIGNED_MAX = 4294967296;

	if (num < 0)
		return (print_number(UNSIGNED_MAX + num));

	return (print_number(num));
}

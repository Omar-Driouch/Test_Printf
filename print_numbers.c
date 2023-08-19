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
	long dec = va_arg(b, long);
	long i, bin = 0;

	for (i = 1; dec != 0; i *= 10)
	{
		bin += (dec % 8) * i;
		dec /= 8;
	}

	return (print_number(bin));
}

/**
 * printf_o - Prints a number in base 8 (octal)
 * @o: Number to print in base 8
 *
 * Return: Length of the printed number
 */
int printf_o(va_list o)
{
	long dec = va_arg(o, long);
	long i, oct = 0;

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

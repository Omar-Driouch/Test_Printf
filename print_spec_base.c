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
	int i = 32 - 1, len = 0;
	int shiftter, non_zero_found = 0;

	while (i >= 0)
	{
		shiftter = (1 << i);
		if (dec & shiftter)
		{
			len += _putchar('1');
			non_zero_found = 1;
		}
		else if (non_zero_found || i == 0)
			len += _putchar('0');
		i--;
	}
	return (len);
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
 * printf_x - Prints a number in base 16 (Hex Lowercase)
 * @x: Number to print
 *
 * Return: Length of the printed number
 */
int printf_x(va_list x)
{
	return (printf_x_or_X(va_arg(x, int), 1));
}

/**
 * printf_X - Prints a number in base 16 (Hex Uppercase)
 * @X: Number to print
 *
 * Return: Length of the printed number
 */
int printf_X(va_list X)
{
	return (printf_x_or_X(va_arg(X, int), 0));
}

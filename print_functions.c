/**
 * print_functions.c - This is the Print Function file
 * Contains all needed functions for each specifier
 * And thier helper functions
 * Current handled Specifiers are: c, s, d, i
*/

#include "main.h"
#include <unistd.h>



/* <============= These are the helper funcions =============> */

/**
 * _putchar - Writes a character to standard output
 * @c: The character to be written
 *
 * Return: On success, 1. On error, -1 is returned and errno is set.
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
	int len = 0;

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

/* <============= These are the Specifier funcions =============> */

/**
 * print_c - Prints a character
 * @c: Character to print
 *
 * Return: Length of the printed character (1)
 */
int print_c(va_list c)
{
	char ch = va_arg(c, int);
	char null_char = ' ';

	if (c == NULL)
		return (_putchar(null_char));

	return (_putchar(ch));
}

/**
 * print_s - Prints a string
 * @s: String to print
 *
 * Return: Length of the printed string
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	char *null_str = "(null)";
	int i;

	if (str == NULL)
	{
		for (i = 0; null_str[i] != '\0'; i++)
			_putchar(null_str[i]);
		return (i);
	}

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_d - Prints a decimal
 * @d: Decimal to print
 *
 * Return: Length of the printed decimal
 */
int print_d(va_list d)
{
	int decimal = va_arg(d, int);

	return (print_number(decimal));
}

/**
 * print_d - Prints a number in base 8 (octal)
 * @o: Number to print in base 8
 *
 * Return: Length of the printed number
 */
int print_o(va_list o)
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

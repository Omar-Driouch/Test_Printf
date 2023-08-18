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
	int n = va_arg(d, int);
	unsigned int i, len = 0, mag = 1, tmp = n;
	/* int null_number = 0;

	if (n == NULL)
		return (_putchar(null_number + '0')); */

	if (n < 0)
	{
		n *= -1;
		tmp = n;
		_putchar('-');
		len++;
	}

	while (tmp >= 10)
	{
		tmp /= 10;
		mag *= 10;
	}

	for (i = 1; i <= mag; i *= 10)
		len += _putchar((n / (mag / i)) % 10 + '0');

	return (len);
}

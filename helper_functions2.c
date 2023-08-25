#include "main.h"
/**
 * printf_Lu - convert an input argument into unsigned int
 * @u: the input args
 *
 * Return: the count  of printed numbers
 */
int printf_Lu(va_list u)
{
	unsigned long num = va_arg(u, unsigned long);
	char buffer[30];
	int index = 0, i;
	int lent = 0;

	if (num == 0)
	{
		lent += _putchar('0');
		return (lent);
	}

	while (num > 0)
	{
		buffer[index++] = '0' + (num % 10);
		num /= 10;
	}

	for (i = index - 1; i >= 0; i--)
	{
		lent += _putchar(buffer[i]);
	}

	return (lent);
}
/**
 * print_base - Print an unsigned long integer in a specified base.
 *
 * This function prints an unsigned long integer in the specified base
 * (octal, decimal, or hexadecimal).
 *
 * @u: A va_list that contains the argument to be printed.
 * @base: The base in which to print the number (e.g., 8 for octal, 10
 * for decimal, 16 for hexadecimal).
 * @iUpper: Set to 1 to use uppercase letters for hexadecimal (A-F)
 * or 0 for lowercase (a-f).
 *
 * Return: The total number of characters printed.
 */
int print_base(va_list u, int base, int iUpper)
{
	unsigned long num = va_arg(u, unsigned long);
	char buffer[30], chr = 'a';
	int index = 0, i;
	int lent = 0;

	if (iUpper)
		chr = 'A';

	if (num == 0)
	{
		lent += _putchar('0');
		return (lent);
	}

	while (num > 0)
	{
		int digit = num % base;

		buffer[index++] = (digit < 10) ? '0' + digit : chr + digit - 10;
		num /= base;
	}

	for (i = index - 1; i >= 0; i--)
	{
		lent += _putchar(buffer[i]);
	}

	return (lent);
}


/**
 * _lentofInt - calculate lenght of integer
 * @num: long integer
 *
 * Return: lenght
*/
int _lentofInt(long num)
{
	int lent = 0;

	if (num == 0)
		return (1);
	if ((long)num < 0)
		lent++;

	while (num != 0)
	{
		lent++;
		num /= 10;
	}

	return (lent);
}

/**
 * _ConverTobase - Convert an unsigned long integer to a string in the
 * specified base.
 *
 * @num: The unsigned long integer to convert.
 * @base: The base for the conversion (e.g., 10 for decimal, 16 for hex).
 * @iupper: Use uppercase letters for hexadecimal digits (A-F) if true.
 *
 * Return: A dynamically allocated string with the converted value.
 */

char *_ConverTobase(unsigned long num, int base, int iupper)
{
	char buffer[50], *Tobase, chr = 'a';
	int index = 0, i;
	int lent = 0, j = 0;

	if (iupper)
		chr = 'A';

	if (num == 0)
	{
		lent++;
		return ("0");
	}

	while (num > 0)
	{
		int digit = num % base;

		buffer[index++] = (digit < 10) ? '0' + digit : chr + digit - 10;
		num /= base;
	}
	Tobase = (char *)malloc((index + 1) * sizeof(char));

	if (Tobase == NULL)
		return (NULL);

	for (i = index - 1; i >= 0; i--, j++)
	{
		lent += Tobase[j] = buffer[i];
	}

	Tobase[j] = '\0';
	return (Tobase);
}
/**
 * _strlen - returns length of string
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

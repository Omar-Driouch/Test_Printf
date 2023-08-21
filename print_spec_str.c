#include "main.h"

/**
 * printf_s - takes an array of char and print it using the buffer
 * 1024 size
 * @s: va_list containing the argument to be printed.
 * Return: the lenght of the printfed string
 */
int printf_s(va_list s)
{
	int counter = 0;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		counter += _putchar(*str);
		str++;
	}

	return (counter);
}

/**
 * printf_c - Custom printf function to print a character.
 * @c: va_list containing the argument to be printed.
 * Return: The number of characters printed.
 */

int printf_c(va_list c)
{
	char ch = va_arg(c, int);
	char null_char = ' ';

	if (c == NULL)
		return (_putchar(null_char));

	return (_putchar(ch));
}

/**
 * printf_S - Custom format specifier function for printing strings
 * @S: A va_list containing the argument to be printed
 *
 * This function is a custom format specifier for printing strings with special
 * handling for non-printable and extended ASCII characters.
 * it uses the our own _printf to printf the hexa values
 *
 * Return: The total length of printed characters.
 */
int printf_S(va_list S)
{
	char *bigS = va_arg(S, char *);
	int length = 0;

	if (bigS == NULL)
		bigS = "(null)";

	while (*bigS != '\0')
	{
		if (*bigS >= 0 && *bigS <= 10)
		{
			_printf("\\x0%X", (unsigned char)*bigS);
			length += 4;
		}
		else if (*bigS < 32)
		{
			_printf("\\x%X", (unsigned char)*bigS);
			length += 4;
		}
		else if (*bigS >= 127)
		{
			_printf("\\x%X", (unsigned char)*bigS);
			length += 4;
		}
		else
		{
			_putchar(*bigS);
			length++;
		}
		bigS++;
	}
	return (length);
}

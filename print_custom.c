#include "main.h"

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

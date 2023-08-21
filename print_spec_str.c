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

/**
 * printf_r - Prints a string in reverse
 * @r: String to print in reverse
 *
 * Return: Length of the printed string
 */
int printf_r(va_list r)
{
	char *str = va_arg(r, char *);
	char *rev;
	int i = 0, j = 0, len = 0, isnewLine = 0;

	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
		{
			isnewLine = 1;
		}
	}

	rev = (char *)malloc(i + 2);
	if (rev == NULL)
		return (0);

	for (j = i; j >= 0; j--)
	{
		if (str[j] != '\n')
			rev[i - 1 - j] = str[j];
	}

	rev[i++] = '\0';
	if (isnewLine == 1)
		len += _printf("%s\n", rev);
	else
		len += _printf("%s", rev);

	free(rev);

	return (len);
}

int printf_R(va_list R)
{
	char *s = va_arg(R, char *);
	char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 26 * 2; j++)
		{
			if (s[i] == chars[j])
			{
				_putchar(rot13[j]);
				break;
			}
		}
		if (j == 26 * 2)
			_putchar(s[i]);
	}
	return (i);
}

/**
 * handle_flag - Handles the flags '+', ' ', '#'
 * @format: The format containing the flags
 * @index_ptr: Pointer the the flag index
 *
 * Return: 1 if flag found, otherwise 0
 */
int handle_flag(const char *format, int *index_ptr)
{
	int i, spec_index, is_plus = 0, is_space = 0;

	i = *index_ptr + 1;
	while (format[i] != '\0')
	{
		if (format[i] == 'i' || format[i] == 'd')
		{
			spec_index = i;
			break;
		}
		if (format[i] != '+' && format[i] != ' ' && format[i] != '#')
			return (0);
		i++;
	}

	i = *index_ptr + 1;
	while (i < spec_index)
	{
		while (format[i] == '+')
		{
			is_plus = 1;
			i++;
		}
		while (format[i] == ' ')
		{
			is_space = 1;
			i++;
		}
		while (format[i] == '#')
			i++;
	}

	*index_ptr = spec_index - 1;
	if (is_plus)
		return (_putchar('+'));
	if (is_space)
		return (_putchar(' '));

	return (0);
}

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
 * printf_r - prints the string in a reversed form
 * @r: A va_list containing the argument to be printed
 *
 * Return: The total length of printed characters.
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
		len = _printf("%s\n", rev);
	else
		len = _printf("%s", rev);

	free(rev);

	return (len);
}

/**
 * printf_R - Print a string with ROT13 encoding.
 *
 * This function takes a string as a variable argument and prints it to the
 * standard output with ROT13 encoding. ROT13 is a simple letter substitution
 * cipher that replaces each letter with the letter 13 positions forward in the
 * alphabet. Non-alphabet characters are left unchanged.
 *
 * @R: A va_list containing the string to be printed with ROT13 encoding.
 *
 * Return: The number of characters printed, excluding the null-terminator.
 */

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
 * get_flag - Extract and process formatting flags from a format string.
 *
 * This function parses a format string for a specific flag
 * character (e.g., '+',
 * ' ' or flag for integers like 'd', 'i', 'o', 'x', 'X') starting from the
 * given index and processes it. It handles the flag character and optional
 *  space
 * or plus sign, making appropriate function calls based on the detected flag
 *
 * @str:  A pointer to the format string being processed.
 * @i:    The index in the format string where the flag character is located
 * @flag:  The flag character to be processed ('#' ,'+', ' ').
 * @ls: a va_list containing the variable arguments for formatting.
 *
 * Return The updated index in the format string after processing the flag.
 */

int get_flag(const char *str, int i, char flag, va_list ls)
{
	char ISflag = '\0';
	int keepI = i;
	int num;
	va_list copy;
	va_copy(copy, ls);

	num = va_arg(copy, int);
	while (str[i + 1] == flag || str[i + 1] == ' ' || str[i + 1] == '+')
	{
		if (str[i + 2] == 'd' || str[i + 2] == 'i')
		{
			if (str[i + 1] == '+' && num >= 0)
				_putchar('+');
			else if (str[i + 1] == ' ' && num >= 0)
				_putchar(' ');
			ISflag = 'd';
			printf_i(ls);
		}
		else if (str[i + 2] == 'o')
		{
			ISflag = 'o';
			printf_o(ls);
		}
		else if (str[i + 2] == 'x')
		{
			ISflag = 'x';
			printf_x(ls);
		}
		else if (str[i + 2] == 'X')
		{
			ISflag = 'X';
			printf_X(ls);
		}
		i++;
	}
	if (ISflag == '\0')
		i = keepI;

	return (i);
}
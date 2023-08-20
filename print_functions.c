#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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

int printf_x_or_X(unsigned int num, int IsLower)
{

	int i, length = 0;
	int chr = 65;
  
	if (IsLower)
	 
		chr = 97;

	if (num == 0)
	{
		_putchar('0');
		return 1;
	}

	for (i = 28; i >= 0; i -= 4)
	{
		int hex_digit = (num >> i) & 0xF;

		if (hex_digit > 0 || length > 0)
		{
			if (hex_digit < 10)
				_putchar(hex_digit + '0');
			else
				_putchar(hex_digit - 10 + chr);

			length++;
		}
	}

	return length;
}

int printf_x(va_list args)
{
	return (printf_x_or_X(va_arg(args, int), 1));
}


int printf_X(va_list args)
{
	return (printf_x_or_X(va_arg(args, int), 0));
} 
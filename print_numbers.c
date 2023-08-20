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

/**
 * printf_u - convert an input argument into unsigned int
 * @u: the input args
 *
 * Return: the count  of printed numbers
 */

int printf_u(va_list u)
{
	long num = va_arg(u, int);
	const long UNSIGNED_MAX = 4294967296;

	if (num < 0)
		return (print_number(UNSIGNED_MAX + num));

	return (print_number(num));
}

/**
 * printf_x_or_X - Converts and prints a decimal to its hex value
 * @num: Decimal number to convert
 * @is_lower: Decides to print the hex either in upper or lower case
 *
 * Return: Length of the printed number
 */
int printf_x_or_X(unsigned int num, int is_lower)
{
	int i, len = 0;
	int hex_digit;
	char char_base = 'A';

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	if (is_lower)
		char_base = 'a';

	for (i = 28; i >= 0; i -= 4)
	{
		/* Shifting and using Bitwise opearnd to take the Hex value */
		hex_digit = (num >> i) & 0xF;

		if (hex_digit > 0 || len > 0)
		{
			if (hex_digit < 10)
				len += _putchar(hex_digit + '0');
			else
				len += _putchar(hex_digit - 10 + char_base);
		}
	}
	return (len);
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

/**
 * printf_p - Prints the address of the given pointer
 * @p: Pointer to print its address
 *
 * Return: Length of the printed address
 */
int printf_p(va_list p)
{
	void *addr = va_arg(p, void *);
	char *null_addr = "(nil)";
	int i, hex_num_digits, start_printing_digits = 0, len = 0;
	unsigned long addr_value;

	if (addr == NULL)
	{
		while (*null_addr != '\0')
			len += _putchar(*(null_addr++));
		return (len);
	}

	addr_value = (unsigned long)addr;

	len += _putchar('0');
	len += _putchar('x');

	if (addr == 0)
		return (_putchar('0') + len);

	hex_num_digits = (sizeof(void *) * 2);

	i = (hex_num_digits - 1) * 4;
	while (i >= 0)
	{
		int hex_digit = (addr_value >> i) & 0xF;

		if (hex_digit > 0 || start_printing_digits)
		{
			start_printing_digits = 1;
			if (hex_digit < 10)
				len += putchar(hex_digit + '0');
			else
				len += putchar(hex_digit - 10 + 'a');
		}
		i -= 4;
	}
	return (len);
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

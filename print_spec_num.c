#include "main.h"

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
 * printf_p - Prints the address of the given pointer
 * @p: Pointer to print its address
 *
 * Return: Length of the printed address
 */
int printf_p(va_list p)
{
	void *addr = va_arg(p, void *);
	unsigned long int addr_value;
	char *null_addr = "(nil)";
	int i = 0, j, len = 0;
	int hex_digits[64];

	if (addr == NULL)
	{
		while (*null_addr != '\0')
			len += _putchar(*(null_addr++));
		return (len);
	}

	addr_value = (unsigned long int)addr;

	if (addr_value == 0)
		return (_putchar('0'));

	len += _putchar('0');
	len += _putchar('x');

	while (addr_value > 0)
	{
		hex_digits[i] = addr_value % 16;
		addr_value /= 16;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (hex_digits[j] < 10)
			len += _putchar(hex_digits[j] + '0');
		else
			len += _putchar(hex_digits[j] - 10 + 'a');
	}

	return (len);
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
 * @s:  A pointer to the format string being processed.
 * @i:    The index in the format string where the flag character is located
 * @ar_ls: a va_list containing the variable arguments for formatting.
 *
 * Return: The updated index in the format string after processing the flag.
 */

int get_flag(const char *s, int *i, va_list ar_ls)
{
	int keepI = *i, n = *i, num, lent = 0, w = 0;
	va_list copy;

	va_copy(copy, ar_ls);
	num = va_arg(copy, int);
	if (s[n + 1] == ' ' && s[n + 2] == '%')
	{
		*i += 2;
		return (_putchar('%'));
	}
	
	while (s[n + 1] == '#' || s[n + 1] == ' ' || s[n + 1] == '+')
	{
		if (s[n + 2] == 'd' || s[n + 2] == 'i')
		{
			lent += (s[n + 1] == '+' && num >= 0) ? _putchar('+') :
			 (s[n + 1] == ' ' && num >= 0) ? _putchar(' ') : 0;
			lent += printf_i(ar_ls);
		}
		else if (s[n + 2] == 'o')
		{
			s[n + 2] == 'o' && s[n + 1] != ' ' && s[n + 1] != '+' ? _putchar('0') : w++;
			lent += printf_o(ar_ls);
		}
		else if (s[n + 2] == 'x')
		{
			s[n + 2] == 'x' && s[n + 1] != ' ' && s[n + 1] != '+' ? _printf("0x") : w++;
			lent += printf_x(ar_ls);
		}
		else if (s[n + 2] == 'X')
		{
			s[n + 2] == 'X' && s[n + 1] != ' ' && s[n + 1] != '+' ? _printf("0X") : w++;
			lent += printf_X(ar_ls);
		}
		n++;
	}

	
	handleLH(s, i, ar_ls);
	n = (lent == 0) ? keepI : n;
	*i = n;
	return (lent);
}



int handleLH(const char *s, int *i, va_list ar_ls)
{

	int keepI = *i, n = *i, num, lent = 0, w = 0;
	va_list copy;

	va_copy(copy, ar_ls);
	num = va_arg(copy, int);
	if (s[n + 1] == ' ' && s[n + 2] == '%')
	{
		*i += 2;
		return (_putchar('%'));
	}
	
	while (s[n + 1] == 'l' || s[n + 1] == 'h' )
	{
		if (s[n + 2] == 'd' || s[n + 2] == 'i')
		{
			lent += (s[n + 1] == '+' && num >= 0) ? _putchar('+') :
			 (s[n + 1] == ' ' && num >= 0) ? _putchar(' ') : 0;
			lent += printf_i(ar_ls);
		}
		else if (s[n + 2] == 'o')
		{
			s[n + 2] == 'o' && s[n + 1] != ' ' && s[n + 1] != '+' ? _putchar('0') : w++;
			lent += printf_o(ar_ls);
		}
		else if (s[n + 2] == 'x')
		{
			s[n + 2] == 'x' && s[n + 1] != ' ' && s[n + 1] != '+' ? _printf("0x") : w++;
			lent += printf_x(ar_ls);
		}
		else if (s[n + 2] == 'X')
		{
			s[n + 2] == 'X' && s[n + 1] != ' ' && s[n + 1] != '+' ? _printf("0X") : w++;
			lent += printf_X(ar_ls);
		}
		n++;
	}

	
	 
	n = (lent == 0) ? keepI : n;
	*i = n;
	return (lent);

	 


}


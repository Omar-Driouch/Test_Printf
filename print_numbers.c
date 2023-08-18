#include "main.h"

/**
 * printf_binary - Custom printf conversion for binary integer printing.
 *
 * Takes a va_list with an integer, converts it to binary
 * and prints the reversed binary string.
 *
 * @ls:ls - va_list with the integer to convert and print.
 *
 * Return:Result of the print_rev function, indicating printed characters count.
 */

int printf_binary(va_list ls)
{
	int num = va_arg(ls, int);
	int i = 0;
	char bin[sizeof(int) * 8 + 1];

	while (num > 0)
	{
		bin[i] = num % 2 + '0';
		num = num / 2;
		i++;
	}
	bin[i] = '\0';

	return print_rev(bin);
}

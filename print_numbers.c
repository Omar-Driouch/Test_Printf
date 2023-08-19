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
	int i = 0, result = 0;
	char *bin = (char *)malloc((count_binary_digits(num) + 1) * sizeof(char));

	if (bin == NULL)
	{
		return (-1); 
	}
	while (num > 0)
	{
		bin[i] = num % 2 + '0';
		num = num / 2;
		i++;
	}
	bin[i] = '\0';

	result = print_rev(bin);

	free(bin);

	return result;
}

/**
 * count_binary_digits -  count how many digits in the binary digit
 * @num: the number
 * 
 * Return: the counted digits
*/

int count_binary_digits(int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}

	while (num > 0)
	{
		num = num / 2;
		count++;
	}

	return (count);
}
#include "main.h"

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

#include "main.h"

/**
 * print_rev - a fucntion that prints reverse string
 * @s: string
 * Return: void
 */

int print_rev(char *s)
{
	int i = 0, j = 0;
	int counter = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
		counter++;
	}

	return (counter);
}
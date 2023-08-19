#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

	int len2;

	len2 = _printf("%b\n", 111222333);
	_printf("%d\n", len2);


	len2 = printf("%b\n", 111222333);
	printf("%d", len2);

	return (0);
}
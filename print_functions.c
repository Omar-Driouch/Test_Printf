#include <unistd.h>

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


int print_c(va_list)
{

}


int print_s(va_list)
{

}


int print_d(va_list)
{

}


int print_b(va_list)
{

}

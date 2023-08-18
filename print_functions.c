#include <main.h>

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
 * printf_string - takes an array of char and print it using the buffer 1024 size
 * @buffer: a string;
*/


int printf_string(char *buffer)
{
	int counter = 0;
	while (*buffer != '\0') 
		counter += _putchar(*buffer++);
	return (counter);
}
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
 * printf_string - takes an array of char and print it using the buffer 1024 size
 * @ls: va_list containing the argument to be printed.
 * Return: the lenght of the printfed string
 */

int printf_s(va_list ls)
{
    int counter = 0;
    char *str = va_arg(ls, char *);

    if (str == NULL)
        return counter;

    while (*str != '\0')
    {
        counter += _putchar(*str);
        str++;
    }

    return counter;
}

/**
 * printf_i - Custom printf function to print an integer.
 * @ls: va_list containing the argument to be printed.
 *
 * This function is used as part of a custom printf implementation to print an integer
 * argument. It handles both positive and negative integers, calculates the number of
 * digits in the integer, and prints each digit separately.
 *
 * Return: The number of characters printed.
 */
int printf_i(va_list ls)
{
    int counter = 0, i, numDigits = 0, divisor = 1, temp;
    int num = (int)va_arg(ls, int);

    if (num == 0)
    {
        _putchar('0');
        return (0);
    }
    if (num < 0)
    {
        _putchar('-');
        num = -num;
    }
    temp = num;
    while (temp > 0)
    {
        temp /= 10;
        numDigits++;
    }

    for (i = 1; i < numDigits; i++)
        divisor *= 10;

    while (divisor > 0)
    {
        int digit = num / divisor;
        _putchar(digit + '0');
        num %= divisor;
        divisor /= 10;
        counter++;
    }

    return counter;
}

/**
 * printf_char - Custom printf function to print a character.
 * @ls: va_list containing the argument to be printed.
 * Return: The number of characters printed.
 */

int printf_char(va_list ls)
{
    char ch = va_arg(ls, int);
    char null_char = ' ';

    if (ls == NULL)
        return (_putchar(null_char));

    return (_putchar(ch));
}

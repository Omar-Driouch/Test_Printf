#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct formatter - A struct of specifiers with their
 * corresponding print's function
 * @spec: The specifier
 * @func: The print's function for @spec
 */
typedef struct formatter
{
	char spec;
	int (*func)(va_list);
} formatter_t;

/* Prototypes */
int _printf(const char *format, ...);
int (*get_right_func(const char *s))(va_list);
int _putchar(char c);
int print_number(long num);
int printf_x_or_X(unsigned int num, int IsLower);

/* Specifiers functions */
int printf_s(va_list);
int printf_i(va_list);
int printf_c(va_list);
int printf_b(va_list);
int printf_o(va_list);
int printf_u(va_list);
int printf_x(va_list);
int printf_X(va_list);
int printf_S(va_list);
int printf_p(va_list);

#endif /* MAIN_H */

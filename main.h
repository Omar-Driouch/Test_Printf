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
int _putchar(char c);
int printf_c(va_list c);
int printf_s(va_list s);
int printf_i(va_list i);
int printf_b(va_list b);
int printf_o(va_list o);
int printf_u(va_list u);
int printf_x(va_list x);
int printf_X(va_list X);

int printf_x_or_X(unsigned int num, int is_lower);
int print_number(long num);
int (*get_right_func(const char *s))(va_list);

#endif /* MAIN_H */

#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdarg.h>
#include <stdlib.h>
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
int (*get_formatting_func(char c))(va_list);

/* Print functions for each Specifier */
int print_c(va_list);
int print_s(va_list);
int print_d(va_list);
int print_o(va_list);

#endif /* MAIN_H */

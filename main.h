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
int get_flag(const char *str, int *i, va_list ls);
int _putchar(char c);
int print_number(long num);
int printf_x_or_X(unsigned int num, int IsLower);
int handleLH(const char *s, int *i, va_list ar_ls);
int print_largeNum(unsigned long num);

int customFunction_flag(int num, const char *s, int n, int le, va_list ls);
int printf_Lu(va_list u);
int print_base(va_list u, int base, int iUpper);

/*handle task 9 cases %*d and %6d */
int Handle_digits_Field(const char *s, int *i, va_list ar_ls);
int Handle_Char_Field(const char *s, int *i, va_list ar_ls);
int Handle_Star_Field(const char *s, int *i, va_list ar_ls);
int Handle_char_with_star(const char *s, int *i, va_list ar_ls);
int Handle_Star_Field_2(const char *s, int *i, va_list ar_ls);
int _lentofInt(long num);
char *_ConverTobase(unsigned long num, int base, int iUpper);
int _strlen(char *s);
int _isdig(int);

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
int printf_r(va_list);
int printf_R(va_list);

#endif /* MAIN_H */

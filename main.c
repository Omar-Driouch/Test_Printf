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
	char *str = "test\n";
	int len;
	int len2;
	unsigned int ui;
	/* void *addr; */

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	/* addr = (void *)0x7ffe637541f0; */


	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	
	/* _printf("Unsigned:[%u]\n", ui); */
	/* printf("Unsigned:[%u]\n", -4294967288); */

	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);

	/* _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui); */


	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");


	/* _printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr); */


	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");


	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);

	
	/* _printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n"); */

	printf(" --------- Task 0 --------- \n");

	/* printf("Let's print a simple sentence.\n"); */
	_printf("Let's print a simple sentence.\n");

	printf("%c\n", 'S');
	_printf("%c\n", 'S');

	printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');

	printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);

	printf("%s", "This sentence is retrieved from va_args!\n");
	_printf("%s", "This sentence is retrieved from va_args!\n");

	/* printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know"); */
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "----");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "----");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "----");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "----");

	/* printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0); */

	printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');

	printf("%%");
	_printf("Should print a single percent sign: %%\n");
	printf("%%");
	_printf("Should print a single percent sign: %%\n");

	printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');

	printf("css%ccs%scscscs", 'T', "Test");
	 _printf("css%ccs%scscscs", 'T', "Test");


	/* printf(str);
	_printf(str); */

	printf("man gcc:\n%s", str);
	_printf("man gcc:\n%s", str);

	/* printf(NULL);
	_printf(NULL); */

	printf("%c\n", '\0');
	_printf("%c\n", '\0');

	/* printf("%");
	_printf("%"); */

	/* printf("%!\n");
	_printf("%!\n"); */

	/* printf("%K\n");
	_printf("%K\n"); */


	return (0);
}

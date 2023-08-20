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
 	long int l = 2147483647;
   
	long int l2 = UINT_MAX + 1024;
	long int res = (long int)INT_MAX * 2;
	

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	/* addr = (void *)0x7ffe637541f0; */


	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);

	_printf("Unsigned octal:[%o]\n", -10);
	printf("Unsigned octal:[%o]\n", -10);

	_printf("Unsigned binary:[%b]\n", 15);
	_printf("Unsigned binary:[%b]\n", -15);

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

	
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");


	printf("\n<==== Task 0 ====>\n");


	printf("Let's print a simple sentence.\n");
	_printf("Let's print a simple sentence.\n");

	printf("%c\n", 'S');
	_printf("%c\n", 'S');

	printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');

	printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);

	printf("%s", "This sentence is retrieved from va_args!\n");
	_printf("%s", "This sentence is retrieved from va_args!\n");

	printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");

	printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);

	printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');

	printf("%%\n");
	_printf("Should print a single percent sign: %%\n");
	printf("%%\n");
	_printf("Should print a single percent sign: %%\n");

	printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');

	printf("css%ccs%scscscs\n", 'T', "Test");
	 _printf("css%ccs%scscscs\n", 'T', "Test");


	printf(str);
	_printf(str);

	printf("man gcc:\n%s", str);
	_printf("man gcc:\n%s", str);



    printf("===printing NULL bellow=====\n");
	
	printf(NULL);
	_printf(NULL);
 	printf("===printing  bellow=====\n");
	printf("%c\n", '\0');
	_printf("%c\n", '\0');

 	printf("===printing pertenteg bellow=====\n");
	printf("%");
	_printf("%");

	 printf("%!\n");
	_printf("%!\n"); 

	printf("%K\n");
	_printf("%K\n");

	printf("\n<==== Task 1 ====>\n");


	_printf("%d\n", 1024);
	printf("%d", 1024);
	printf("\n------------------- CASE (1) -------------------\n");
	_printf("%d\n", -1024);
	printf("%d", -1024);
	printf("\n------------------- CASE (2) -------------------\n");
	_printf("%d\n", 0);
	printf("%d", 0);
	printf("\n------------------- CASE (3) -------------------\n");
	_printf("%d\n", INT_MAX);
	printf("%d", INT_MAX);
	printf("\n------------------- CASE (4) -------------------\n");
	/* we have an issue  out put -0  normally -2147483648 */
	_printf("%d\n", INT_MIN);
	printf("%d", INT_MIN);
	printf("\n------------------- CASE (5) -------------------\n");
	_printf("%d\n", l);
	printf("%d", l);
	printf("\n------------------- CASE (6) -------------------\n");
	_printf("%d\n", l);
	printf("%d", l);
	printf("\n------------------- CASE (7) -------------------\n");
	_printf("There is %d bytes in %d KB\n", 1024, 1);
	printf("There is %d bytes in %d KB\n", 1024, 1);
	printf("\n------------------- CASE (8) -------------------\n");
	_printf("%d - %d = %d\n", 1024, 2048, -1024);
	printf("%d - %d = %d\n", 1024, 2048, -1024);
	printf("\n------------------- CASE (9) -------------------\n");
	/* we have an isssue here the output is -0 + 2147483647 = -1  the expected value is -2147483648 + 2147483647 = -1 */
	_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n------------------- CASE (10) -------------------\n");
	_printf("%i\n", 1024);
	printf("%i", 1024);
	printf("\n------------------- CASE (11) -------------------\n");
	_printf("%i\n", -1024);
	printf("%i", -1024);
	printf("\n------------------- CASE (12) -------------------\n");
	_printf("%i\n", 0);
	printf("%i", 0);
	printf("\n------------------- CASE (13) -------------------\n");
	_printf("%i\n", INT_MAX);
	printf("%i", INT_MAX);
	printf("\n------------------- CASE (14) -------------------\n");
	/* we have an issue  out put -0  normally -2147483648 */
	_printf("%i\n", INT_MIN);
	printf("%i", INT_MIN);
	printf("\n------------------- CASE (15) -------------------\n");
	_printf("%i\n", l);
	printf("%i", l);
	printf("\n------------------- CASE (16) -------------------\n");
	_printf("%i\n", l);
	printf("%i", l);
	printf("\n------------------- CASE (17) -------------------\n");
	_printf("There is %i bytes in %i KB\n", 1024, 1);
	printf("There is %i bytes in %i KB\n", 1024, 1);
	printf("\n------------------- CASE (18) -------------------\n");
	_printf("%i - %i = %i\n", 1024, 2048, -1024);
	printf("%i - %i = %i\n", 1024, 2048, -1024);
	printf("\n------------------- CASE (19) -------------------\n");
	/* we have an isssue here the output is -0 + 2147483647 = -1  the expected value is -2147483648 + 2147483647 = -1 */
	_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n------------------- CASE (20) -------------------\n");
	_printf("%d == %i\n", 1024, 1024);
	printf("%d == %i\n", 1024, 1024);
	printf("\n------------------- CASE (21) -------------------\n");
	_printf("iddi%diddiiddi\n", 1024);
	printf("iddi%diddiiddi\n", 1024);
	printf("\n------------------- CASE (22) -------------------\n");
	_printf("%d\n", 10000);
	printf("%d", 10000);
	printf("\n------------------- CASE (23) -------------------\n");
	_printf("%i\n", 10000);
	printf("%i", 10000);

	printf("\n<==== Task 1 ====>\n");

	/* // Test case 1 */
	printf("Test case 1\n");
	_printf("%b\n", 1024);
	printf("%b\n", 1024);

	/* // Test case 2 */
	printf("\nTest case 2\n");
	_printf("%b\n", -1024);
	printf("%b\n", -1024);

	/* // Test case 3 */
	printf("\nTest case 3\n");
	_printf("%b\n", 0);
	printf("%b\n", 0);

	/* // Test case 4 */
	printf("\nTest case 4\n");
	_printf("%b\n", UINT_MAX);
	printf("%b\n", UINT_MAX);

	/* // Define and initialize 'l' as a long int equals to UINT_MAX + 1024 */

	/* // Test case 5 */
	printf("\nTest case 5\n");
	_printf("%b\n", l2);
	printf("%b\n", l2);

	/* // Test case 6 */
	printf("\nTest case 6\n");
	_printf("There is %b bytes in %b KB\n", 1024, 1);
	printf("There is %b bytes in %b KB\n", 1024, 1);

	/* // Test case 7 */
	printf("\nTest case 7\n");
	_printf("%b - %b = %b\n", 2048, 1024, 1024);
	printf("%b - %b = %b\n", 2048, 1024, 1024);

	/* // Define 'res' as a long int equals to INT_MAX * 2 */

	/* // Test case 8 */
	printf("\nTest case 8\n");
	_printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);
	printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);

	/* // Test case 9 */
	printf("\nTest case 9\n");
	/* _printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024); */

	/* // Test case 10 */
	printf("\nTest case 10\n");
	/* _printf("uuoxxX%xuoXo\n", 1024);
	printf("uuoxxX%xuoXo\n", 1024); */


	return (0);
}











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
	void *addr;
	char *str = "test\n";
	int len;
	int len2;
	unsigned int ui;
	long int l = 2147483647;

	long int l2 = UINT_MAX + 1024;
	long int res = (long int)INT_MAX * 2;

	long int l3 = UINT_MAX + 1024;

	/* Task 4 Variabls */
	char str4[1020] = "your_initial_string_value_here\n";
	char s[1020] = {0};
	char tmp[147] = "your_tmp_string_value_here\n";
	char tmp2[97] = "your_tmp2_string_value_here\n";

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);

	_printf("Unsigned octal:[%o]\n", -10);
	printf("Unsigned octal:[%o]\n", -10);

	_printf("Unsigned binary:[%b]\n", 15);
	printf("Unsigned binary:[%b]\n", -15);

	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);

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

	printf("\n<==== Task 2 ====>\n");

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
	_printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);

	/* // Test case 10 */
	printf("\nTest case 10\n");
	_printf("uuoxxX%xuoXo\n", 1024);
	printf("uuoxxX%xuoXo\n", 1024);

	_printf("x = %x, -x = %x, X = %X, -X = %X\n", 255, -255, 255, -255);
	printf("x = %x, -x = %x, X = %X, -X = %X\n", 255, -255, 255, -255);

	printf("\n<==== Task 3 ====>\n");

	_printf("%u\n", 1024);
	printf("%u\n", 1024);

	_printf("%u\n", -1024);
	printf("%u\n", -1024);

	_printf("%u\n", 0);
	printf("%u\n", 0);

	_printf("%u\n", UINT_MAX);
	printf("%u\n", UINT_MAX);

	_printf("%u\n", l3);
	printf("%u\n", l3);

	_printf("There is %u bytes in %u KB\n", 1024, 1);
	printf("There is %u bytes in %u KB\n", 1024, 1);

	_printf("%u - %u = %u\n", 2048, 1024, 1024);
	printf("%u - %u = %u\n", 2048, 1024, 1024);

	_printf("%u + %u = %u\n", INT_MAX, INT_MAX, res);
	printf("%u + %u = %u\n", INT_MAX, INT_MAX, res);

	_printf("%o\n", 1024);
	printf("%o\n", 1024);

	_printf("%o\n", -1024);
	printf("%o\n", -1024);

	_printf("%o\n", 0);
	printf("%o\n", 0);

	_printf("%o\n", UINT_MAX);
	printf("%o\n", UINT_MAX);

	_printf("%o\n", l3);
	printf("%o\n", l3);

	_printf("There is %o bytes in %o KB\n", 1024, 1);
	printf("There is %o bytes in %o KB\n", 1024, 1);

	_printf("%o - %o = %o\n", 2048, 1024, 1024);
	printf("%o - %o = %o\n", 2048, 1024, 1024);

	_printf("%o + %o = %o\n", INT_MAX, INT_MAX, res);
	printf("%o + %o = %o\n", INT_MAX, INT_MAX, res);

	_printf("%x\n", 1024);
	printf("%x\n", 1024);

	_printf("%x\n", -1024);
	printf("%x\n", -1024);

	_printf("%x\n", 0);
	printf("%x\n", 0);

	_printf("%x\n", UINT_MAX);
	printf("%x\n", UINT_MAX);

	_printf("%x\n", l3);
	printf("%x\n", l3);

	_printf("There is %x bytes in %x KB\n", 1024, 1);
	printf("There is %x bytes in %x KB\n", 1024, 1);

	_printf("%x - %x = %x\n", 2048, 1024, 1024);
	printf("%x - %x = %x\n", 2048, 1024, 1024);

	_printf("%x + %x = %x\n", INT_MAX, INT_MAX, res);
	printf("%x + %x = %x\n", INT_MAX, INT_MAX, res);

	_printf("%X\n", 1024);
	_printf("%X\n", 1024);

	_printf("%X\n", -1024);
	printf("%X\n", -1024);

	_printf("%X\n", 0);
	printf("%X\n", 0);

	_printf("%X\n", UINT_MAX);
	printf("%X\n", UINT_MAX);

	_printf("%X\n", l3);
	printf("%X\n", l3);

	_printf("There is %X bytes in %X KB\n", 1024, 1);
	printf("There is %X bytes in %X KB\n", 1024, 1);

	_printf("%X - %X = %X\n", 2048, 1024, 1024);
	printf("%X - %X = %X\n", 2048, 1024, 1024);

	_printf("%X + %X = %X\n", INT_MAX, INT_MAX, res);
	printf("%X + %X = %X\n", INT_MAX, INT_MAX, res);

	_printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);

	_printf("uuoxxX%xuoXo\n", 1024);
	printf("uuoxxX%xuoXo\n", 1024);

	printf("\n<========= Task 4 ============>\n");

	_printf(str4);
	printf(str4);

	_printf(str4);
	printf(str4);

	_printf(str4, 123456789);
	printf(str4, 123456789);

	printf("\n==================\n");
	printf("%s %s %s %c %c %s %s %c %s %d\n", str4, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 8);
	printf("\n==================\n");
	_printf("%s %s %s %c %c %s %s %c %s %d\n", str4, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 8);
	printf("\n==================\n");

	printf("%s %s %s %c %c %s %s %c %s %d\n", str4, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 123456789);
	_printf("%s %s %s %c %c %s %s %c %s %d\n", str4, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 123456789);

	printf("%s%b\n", s, INT_MAX);
	_printf("%s%b\n", s, INT_MAX);

	printf("\n================== TASK 5 ===========================\n\n");

	_printf("%S", "No special character.");
	printf("\n");
	_printf("%S", NULL);

	printf("\n------------------------------Test 1----------------------------\n");
	_printf("%S", "\n", 14);

	printf("\n------------------------------Test 2----------------------------\n");
	_printf("%S", "\x01\x02\x03\x04\x05\x06\x07", 14);

	printf("\n------------------------------Test 3----------------------------\n");
	_printf("Could you print some non-printable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");

	printf("\n------------------------------Test 4----------------------------\n");
	_printf("", "");

	printf("\n------------------------------Test 5----------------------------\n");
	_printf("- What did you say?\n- %S\n- That's what I thought.\n", "");

	printf("\n================== TASK 6 ===========================\n\n");

	_printf("%p\n", (void *)0x7fff5100b608);
	_printf("%p", NULL);
	_printf("\nCan you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("\nCan you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	_printf("");
	_printf("\nCan you print an address?\n%p\nNice!\n", (void *)-1);
	_printf("%pppp\n", (void *)0x7fff5100b6f8);

	printf("\n================== TASK 7 ===========================\n\n");

	printf("------------------------------Test 1----------------------------\n");
	_printf("%+d", 1024);
	printf("\n");
	printf("%+d", 1024);
	printf("\n");

	printf("------------------------------Test 2----------------------------\n");
	_printf("%+d", -1024);
	printf("\n");
	printf("%+d", -1024);
	printf("\n");

	printf("------------------------------Test 3--------------------------------\n");
	_printf("%+d", 0);
	printf("\n");
	printf("%+d", 0);
	printf("\n");

	printf("------------------------------Test 4---------------------------\n");
	_printf("%+d", INT_MAX);
	printf("\n");
	printf("%+d", INT_MAX);
	printf("\n");

	printf("------------------------------Test 5----------------------------\n");
	_printf("%+d", INT_MIN);
	printf("\n");
	printf("%+d", INT_MIN);
	printf("\n");

	printf("------------------------------Test 6-----------------------------\n");
	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
	printf("\n");

	printf("------------------------------Test 7-----------------------------\n");
	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
	printf("\n");

	printf("------------------------------Test 8-----------------------------\n");
	_printf("There is %+d bytes in %+d KB\n", 1024, 1);
	printf("\n");
	printf("There is %+d bytes in %+d KB\n", 1024, 1);
	printf("\n");

	printf("------------------------------Test 9-----------------------------\n");
	_printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	printf("\n");
	printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	printf("\n");

	printf("------------------------------Test 10----------------------------\n");
	_printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	printf("------------------------------Test 11----------------------------\n");
	_printf("%+i", 1024);
	printf("\n");
	printf("%+i", 1024);
	printf("\n");

	printf("------------------------------Test 12----------------------------\n");
	_printf("%+i", -1024);
	printf("\n");
	printf("%+i", -1024);
	printf("\n");

	printf("------------------------------Test 13----------------------------\n");
	_printf("%+i", 0);
	printf("\n");
	printf("%+i", 0);
	printf("\n");

	printf("------------------------------Test 14----------------------------\n");
	_printf("%+i", INT_MAX);
	printf("\n");
	printf("%+i", INT_MAX);
	printf("\n");

	printf("------------------------------Test 15----------------------------\n");
	_printf("%+i", INT_MIN);
	printf("\n");
	printf("%+i", INT_MIN);
	printf("\n");

	printf("------------------------------Test 16---------------------------\n");
	_printf("%+i", l);
	printf("\n");
	printf("%+i", l);
	printf("\n");

	printf("------------------------------Test 17---------------------------\n");
	_printf("%+i", l);
	printf("\n");
	printf("%+i", l);
	printf("\n");

	printf("------------------------------Test 18---------------------------\n");
	_printf("There is %+i bytes in %+i KB\n", 1024, 1);
	printf("\n");
	printf("There is %+i bytes in %+i KB\n", 1024, 1);
	printf("\n");

	printf("------------------------------Test 19---------------------------\n");
	_printf("%+i - %+i = %+i\n", 1024, 2048, -1024);
	printf("\n");
	printf("%+i - %+i = %+i\n", 1024, 2048, -1024);
	printf("\n");

	printf("------------------------------Test 20---------------------------\n");
	_printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	printf("------------------------------Test 21-------------------------\n");
	_printf("% d", 1024);
	printf("\n");
	printf("% d", 1024);
	printf("\n");

	printf("------------------------------Test 22-------------------------\n");
	_printf("% d", -1024);
	printf("\n");
	printf("% d", -1024);
	printf("\n");

	printf("------------------------------Test 23-------------------------\n");
	_printf("% d", 0);
	printf("\n");
	printf("% d", 0);
	printf("\n");

	printf("------------------------------Test 24-------------------------\n");
	_printf("% d", INT_MAX);
	printf("\n");
	printf("% d", INT_MAX);
	printf("\n");

	printf("------------------------------Test 25-------------------------\n");
	_printf("% d", INT_MIN);
	printf("\n");
	printf("% d", INT_MIN);
	printf("\n");

	printf("------------------------------Test 26-------------------------\n");
	_printf("% d", l);
	printf("\n");
	printf("% d", l);
	printf("\n");

	printf("------------------------------Test 27-------------------------\n");
	_printf("% d", l);
	printf("\n");
	printf("% d", l);
	printf("\n");

	printf("------------------------------Test 28-------------------------\n");
	_printf("There is % d bytes in % d KB\n", 1024, 1);
	printf("\n");
	printf("There is % d bytes in % d KB\n", 1024, 1);
	printf("\n");

	printf("------------------------------Test 29-------------------------\n");
	_printf("% d - % d = % d\n", 1024, 2048, -1024);
	printf("\n");
	printf("% d - % d = % d\n", 1024, 2048, -1024);
	printf("\n");

	printf("------------------------------Test 30-------------------------\n");
	_printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	printf("------------------------------Test 31------------------------\n");
	_printf("% i", 1024);
	printf("\n");
	printf("% i", 1024);
	printf("\n");

	printf("------------------------------Test 32-------------------\n");
	_printf("% i", -1024);
	printf("\n");
	printf("% i", -1024);
	printf("\n");

	printf("------------------------------Test 33-------------------\n");
	_printf("% i", 0);
	printf("\n");
	printf("% i", 0);
	printf("\n");

	printf("------------------------------Test 34-------------------\n");
	_printf("% i", INT_MAX);
	printf("\n");
	printf("% i", INT_MAX);
	printf("\n");

	printf("------------------------------Test 35-------------------\n");
	_printf("% i", INT_MIN);
	printf("\n");
	printf("% i", INT_MIN);
	printf("\n");

	printf("------------------------------Test 36-------------------\n");
	_printf("% i", l);
	printf("\n");
	printf("% i", l);
	printf("\n");

	printf("\n-------------------test case 1--------------------\n");
	_printf("%#o", 1024);

	printf("\n-------------------test case 2--------------------\n");
	_printf("%#o", 0);

	printf("\n-------------------test case 3--------------------\n");
	_printf("%#o", UINT_MAX);

	printf("\n-------------------test case 4--------------------\n");
	_printf("%#x", 1024);

	printf("\n-------------------test case 5--------------------\n");
	_printf("%#x", 0);

	printf("\n-------------------test case 6--------------------\n");
	_printf("%#x", UINT_MAX);

	printf("\n-------------------test case 7--------------------\n");
	_printf("%#X", 1024);

	printf("\n-------------------test case 8--------------------\n");
	_printf("%#X", 0);

	printf("\n-------------------test case 9--------------------\n");
	_printf("%#X", UINT_MAX);

	printf("\n-------------------test case 10--------------------\n");
	_printf("% ");
	_printf("% % % % ");

	return (0);
}
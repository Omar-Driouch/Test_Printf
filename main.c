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
	char s[1020];
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

	_printf("Unsigned binary:[%b]\n", -15);
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

	/* _printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n"); */

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
	printf("%p\n", (void *)0x7fff5100b608);

	_printf("%p\n", NULL);
	printf("%p\n", NULL);

	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);

	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);

	_printf("");
	printf("");

	_printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	printf("Can you print an address?\n%p\nNice!\n", (void *)-1);

	_printf("%pppp\n", (void *)0x7fff5100b6f8);
	printf("%pppp\n", (void *)0x7fff5100b6f8);

	printf("\n");

	printf("\n================== TASK Reversed string ===========================\n\n");

	_printf("Can you print me in reverse %r\n", "Omar");

	_printf("%r", "\nThis sentence is retrieved from va_args!");

	_printf("Complete the sentence: You %r nothing, Jon Snow.\n", "know");

	_printf("Complete the sentence: You %r nothing, Jon Snow.\n", "");

	printf("\n\n================== TASK ROT-13 ===========================\n\n");

	_printf("%R", "Encode me in Rot13!\n");

	_printf("%R", "Rapbqr zr va Ebg13!\n");

	_printf("%R", "Guvf fragrapr vf ergevrirq sebz in_netf!\n");

	_printf("Complete the sentence: You %R nothing, Jon Snow.\n", "xabj");

	_printf("Complete the sentence: You %R nothing, Jon Snow.\n", "");

	printf("\n================== MY TEST CASES ===========================\n\n");

	printf("\n--------------------case normal of d --------------- \n");
	_printf("%d\n", 1024);
	printf("%d\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of x --------------- \n");
	_printf("%x\n", 1024);
	printf("%x\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of X --------------- \n");
	_printf("%X\n", 1024);
	printf("%X\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of o --------------- \n");
	_printf("%o\n", 1024);
	printf("%o\n", 1024);
	printf("\n-------------------- the end  --------------- \n");

	printf("\n============================== TASK 7 ==================================== \n");

	printf("\n--------------------case normal of #d --------------- \n");
	_printf("%#d\n", 1024);
	printf("%#d\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of #x --------------- \n");
	_printf("%#x\n", 1024);
	printf("%#x\n", 1024);

	printf("\n  \n");

	printf("\n--------------------case normal of #X --------------- \n");
	_printf("%#X\n", 1024);
	printf("%#X\n", 1024);

	printf("\n  \n");

	printf("\n--------------------case normal of #o --------------- \n");
	_printf("%#o\n", 1024);
	printf("%#o\n", 1024);
	printf("\n \n");

	printf("\n=================================        ================================= \n");

	printf("\n--------------------case normal of     d --------------- \n");
	_printf("% d\n", 1024);
	printf("% d\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of     x --------------- \n");
	_printf("% x\n", 1024);
	printf("%     x\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of     X --------------- \n");
	_printf("%     X\n", 1024);
	printf("%     X\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of    o --------------- \n");
	_printf("%     o\n", 1024);
	printf("%     o\n", 1024);
	printf("\n \n");

	printf("\n=================================        ================================= \n");

	printf("\n--------------------case normal of    +++++x --------------- \n");
	_printf("%+x\n", 1024);
	printf("%+x\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of  ++++++X --------------- \n");
	_printf("%+X\n", 1024);
	printf("%+X\n", 1024);
	printf("\n  \n");

	printf("\n--------------------case normal of  ++++++o --------------- \n");
	_printf("%+o\n", 1024);
	printf("%+o\n", 1024);
	printf("\n \n");

	printf("\n=================================        ================================= \n");

	printf("\n================== TASK 7 ===========================\n\n");

	_printf("%+d", -1);
	printf("\n");
	printf("%+d", -1);
	printf("\n");

	_printf("%+d", INT_MAX);
	printf("\n");
	printf("%+d", INT_MAX);
	printf("\n");

	_printf("%+d", INT_MIN);
	printf("\n");
	printf("%+d", INT_MIN);
	printf("\n");

	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
	printf("\n");

	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
	printf("\n");

	_printf("There is %+d bytes in %+d KB\n", 1024, 1);
	printf("\n");
	printf("There is %+d bytes in %+d KB\n", 1024, 1);
	printf("\n");

	_printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	printf("\n");
	printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	printf("\n");

	_printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	_printf("%+i", 1024);
	printf("\n");
	printf("%+i", 1024);
	printf("\n");

	_printf("%+i", -1024);
	printf("\n");
	printf("%+i", -1024);
	printf("\n");

	_printf("%+i", 0);
	printf("\n");
	printf("%+i", 0);
	printf("\n");

	_printf("%+i", INT_MAX);
	printf("\n");
	printf("%+i", INT_MAX);
	printf("\n");

	_printf("%+i", INT_MIN);
	printf("\n");
	printf("%+i", INT_MIN);
	printf("\n");

	_printf("%+i", l);
	printf("\n");
	printf("%+i", l);
	printf("\n");

	_printf("%+i", l);
	printf("\n");
	printf("%+i", l);
	printf("\n");

	_printf("There is %+i bytes in %+i KB\n", 1024, 1);
	printf("\n");
	printf("There is %+i bytes in %+i KB\n", 1024, 1);
	printf("\n");

	_printf("%+i - %+i = %+i\n", 1024, 2048, -1024);
	printf("\n");
	printf("%+i - %+i = %+i\n", 1024, 2048, -1024);
	printf("\n");

	_printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	_printf("% d", 1024);
	printf("\n");
	printf("% d", 1024);
	printf("\n");

	_printf("% d", -1024);
	printf("\n");
	printf("% d", -1024);
	printf("\n");

	_printf("% d", 0);
	printf("\n");
	printf("% d", 0);
	printf("\n");

	_printf("% d", INT_MAX);
	printf("\n");
	printf("% d", INT_MAX);
	printf("\n");

	_printf("% d", INT_MIN);
	printf("\n");
	printf("% d", INT_MIN);
	printf("\n");

	_printf("% d", l);
	printf("\n");
	printf("% d", l);
	printf("\n");

	_printf("% d", l);
	printf("\n");
	printf("% d", l);
	printf("\n");

	_printf("There is % d bytes in % d KB\n", 1024, 1);
	printf("\n");
	printf("There is % d bytes in % d KB\n", 1024, 1);
	printf("\n");

	_printf("% d - % d = % d\n", 1024, 2048, -1024);
	printf("\n");
	printf("% d - % d = % d\n", 1024, 2048, -1024);
	printf("\n");

	_printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");

	_printf("% i", 1024);
	printf("\n");
	printf("% i", 1024);
	printf("\n");

	_printf("% i", -1024);
	printf("\n");
	printf("% i", -1024);
	printf("\n");

	_printf("% i", 0);
	printf("\n");
	printf("% i", 0);
	printf("\n");

	_printf("% i", INT_MAX);
	printf("\n");
	printf("% i", INT_MAX);
	printf("\n");

	_printf("% i", INT_MIN);
	printf("\n");
	printf("% i", INT_MIN);
	printf("\n");

	_printf("% i", l);
	;
	printf("\n");
	printf("% i", l);
	printf("\n");

	_printf("% i", l);
	printf("\n");
	printf("% i", l);
	printf("\n");

	_printf("% ");
	printf("% ");
	_printf("% % % % ");
	printf("\n");
	printf("% % % % ");
	printf("\n-------------------test 9 -------------------\n");

	_printf("\n-----%ld-----", 12);
	_printf("\n-----%lo-----", 12);
	_printf("\n-----%lx-----", 12);
	_printf("\n-----%lX-----", 12);

	_printf("\n-----%hd-----", 12);
	_printf("\n-----%ho-----", 12);
	_printf("\n-----%hx-----", 12);
	_printf("\n-----%hX-----", 12);

	printf("=================== task 8 and 9==========");


 

	_printf("%ld\n", 1024L);
	printf("%ld\n", 1024L);

	_printf("%ld\n", 1024L);
	printf("%ld\n", 1024L);
	printf("\n");
	_printf("%ld\n", 0L);
	printf("%ld\n", 0L);
	printf("\n");
	_printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MAX);
	printf("\n");
	_printf("%ld\n", LONG_MIN);
	printf("%ld\n", LONG_MIN);
	printf("\n");
	_printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	printf("\n");
	_printf("%ld\n - %ld = %ld\n", 1024L, 2048L, -1024L);
	printf("%ld\n - %ld = %ld\n", 1024L, 2048L, -1024L);
	printf("\n");
	_printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	printf("\n");
	_printf("%li\n", 1024L);
	printf("%li\n", 1024L);
	printf("\n");
	_printf("%li\n", -1024L);
	printf("%li\n", -1024L);
	printf("\n");
	_printf("%li\n", 0L);
	printf("%li\n", 0L);
	printf("\n");
	_printf("%li\n", LONG_MAX);
	printf("%li\n", LONG_MAX);
	printf("\n");
	_printf("%li\n", LONG_MIN);
	printf("%li\n", LONG_MIN);
	printf("\n");

	_printf("%hx\n", 1024);
	printf("%hx\n", 1024);
	printf("\n");
	_printf("%hx\n", 0);
	printf("%hx\n", 0);
	printf("\n");
	_printf("%hx\n", USHRT_MAX);
	printf("%hx\n", USHRT_MAX);
	printf("\n");
	_printf("There is %hx bytes in %hx KB\n", 1024, 1);
	printf("There is %hx bytes in %hx KB\n", 1024, 1);
	printf("\n");
	_printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	printf("\n");
	_printf("%hX\n", 1024);
	printf("%hX\n", 1024);
	printf("\n");
	_printf("%hX\n", 0);
	printf("%hX\n", 0);
	printf("\n");
	_printf("%hX\n", USHRT_MAX);
	printf("%hX\n", USHRT_MAX);
	printf("\n");
	_printf("There is %hX bytes in %hX KB\n", 1024, 1);
	printf("There is %hX bytes in %hX KB\n", 1024, 1);
	printf("\n");
	_printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	printf("\n");
	_printf("%h\n");
	printf("%h\n");
	printf("\n");
	_printf("%l\n");
	printf("%l\n");
	printf("\n");

	printf("\n========================all done ====================\n");

	_printf("% +i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("% +i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX)); 
	printf("\n===========o=========\n");
	printf(" === %d", _printf("%#o", 10));
	printf("\n");
	printf(" === %d", printf("%#o", 10));

	printf("\n===========d=========\n");
	printf(" === %d", _printf("%#d", 10));
	printf("\n");
	printf(" === %d", printf("%#d", 10));

	printf("\n===========x=========\n");
	printf(" === %d", _printf("%#x", 10));
	printf("\n");
	printf(" === %d", printf("%#x", 10));

	printf("\n===========X=========\n");
	printf(" === %d", _printf("%#X", 10));
	printf("\n");
	printf(" === %d", printf("%#X", 10));

	printf("\n======== plu============\n");

	len = _printf("% +i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	len2 = printf("% +i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n======== plu============\n");

	printf("\n===========o=========\n");
	printf(" === %d", _printf("%#o", 0));
	printf("\n");
	printf(" === %d", printf("%#o", 0));

	printf("\n===========d=========\n");
	printf(" === %d", _printf("%#d", 0));
	printf("\n");
	printf(" === %d", printf("%#d", 0));

	printf("\n===========x=========\n");
	printf(" === %d", _printf("%#x", 0));
	printf("\n");
	printf(" === %d", printf("%#x", 0));

	printf("\n===========X=========\n");
	printf(" === %d", _printf("%#X", 0));
	printf("\n");
	printf(" === %d", printf("%#X", 0));

	printf("\n======== plu============\n");

	printf("\n======== Correcttion of task 8	============\n");
	printf("\n------------------- main.0 -------------------\n");

	len = _printf("%ld", 1024L);

	len2 = printf("%ld", 1024L);

	printf("\n  yes mine =>  %d", len);
	printf("\n  not mine =>  %d", len2);

	printf("\n");

	len = _printf("%ld", 1024L);
	len2 = printf("%ld", 1024L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.1 -------------------\n");

	len = _printf("%ld", -1024L);
	len2 = printf("%ld", -1024L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.2 -------------------\n");
	len = _printf("%ld", 0L);
	len2 = printf("%ld", 0L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.5 -------------------\n");
	len = _printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	len2 = printf("There is %ld bytes in %ld KB\n", 1024L, 1L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.8 -------------------\n");
	len = _printf("%li", 1024L);
	len2 = printf("%li", 1024L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.9 -------------------\n");
	len = _printf("%li", -1024L);
	len2 = printf("%li", -1024L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.10 -------------------\n");
	len = _printf("%li", 0L);
	len2 = printf("%li", 0L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.13 -------------------\n");
	len = _printf("There is %li bytes in %li KB\n", 1024L, 1L);
	len2 = printf("There is %li bytes in %li KB\n", 1024L, 1L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.16 -------------------\n");
	len = _printf("%lu", 1024UL);
	len2 = printf("%lu", 1024UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.17 -------------------\n");
	len = _printf("%lu", 0UL);
	len2 = printf("%lu", 0UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.19 -------------------\n");
	len = _printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	len2 = printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.21 -------------------\n");
	len = _printf("%lo", 1024UL);
	len2 = printf("%lo", 1024UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.22 -------------------\n");
	len = _printf("%lo", 0UL);
	len2 = printf("%lo", 0UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.24 -------------------\n");
	len = _printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	len2 = printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.26 -------------------\n");
	len = _printf("%lx", 1024UL);
	len2 = printf("%lx", 1024UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.27 -------------------\n");
	len = _printf("%lx", 0UL);
	len2 = printf("%lx", 0UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.29 -------------------\n");

	len = _printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	len2 = printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.31 -------------------\n");
	len = _printf("%lX", 1024UL);
	len2 = printf("%lX", 1024UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.32 -------------------\n");
	len = _printf("%lX", 0UL);
	len2 = printf("%lX", 0UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.34 -------------------\n");
	len = _printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	len2 = printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.36 -------------------\n");

	len = _printf("%hd", 1024);
	len2 = printf("%hd", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.37 -------------------\n");
	len = _printf("%hd", -1024);
	len2 = printf("%hd", -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.38 -------------------\n");
	len = _printf("%hd", 0);
	len2 = printf("%hd", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.39 -------------------\n");
	len = _printf("%hd", SHRT_MAX);
	len2 = printf("%hd", SHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.40 -------------------\n");
	len = _printf("%hd", SHRT_MIN);
	len2 = printf("%hd", SHRT_MIN);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.41 -------------------\n");
	len = _printf("There is %hd bytes in %hd KB\n", 1024, 1);
	len2 = printf("There is %hd bytes in %hd KB\n", 1024, 1);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.42 -------------------\n");
	len = _printf("%hd - %hd = %hd\n", 1024, 2048, -1024);
	len2 = printf("%hd - %hd = %hd\n", 1024, 2048, -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.43 -------------------\n");
	len = _printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	len2 = printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.44 -------------------\n");

	len = _printf("%hi", 1024);
	len2 = printf("%hi", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.45 -------------------\n");
	len = _printf("%hi", -1024);
	len2 = printf("%hi", -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.47 -------------------\n");
	len = _printf("%hi", 0);
	len2 = printf("%hi", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.48 -------------------\n");
	len = _printf("%hi", SHRT_MAX);
	len2 = printf("%hi", SHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.49 -------------------\n");
	len = _printf("%hi", SHRT_MIN);
	len2 = printf("%hi", SHRT_MIN);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.50 -------------------\n");

	len = _printf("There is %hi bytes in %hi KB\n", 1024, 1);
	len2 = printf("There is %hi bytes in %hi KB\n", 1024, 1);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.51 -------------------\n");

	len = _printf("%hi - %hi = %hi\n", 1024, 2048, -1024);
	len2 = printf("%hi - %hi = %hi\n", 1024, 2048, -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.52 -------------------\n");

	len = _printf("%hu", 1024);
	len2 = printf("%hu", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.53 -------------------\n");
	len = _printf("%hu", USHRT_MAX);
	len2 = printf("%hu", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main.55 -------------------\n");

	len = _printf("There is %hu bytes in %hu KB\n", 1024, 1);
	len2 = printf("There is %hu bytes in %hu KB\n", 1024, 1);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.56 -------------------\n");

	len = _printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.57 -------------------\n");
	len = _printf("%ho", 0);
	len2 = printf("%ho", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.58 -------------------\n");
	len = _printf("%ho", USHRT_MAX);
	len2 = printf("%ho", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.59 -------------------\n");
	len = _printf("There is %ho bytes in %ho KB\n", 1024, 1);
	len2 = printf("There is %ho bytes in %ho KB\n", 1024, 1);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.60 -------------------\n");

	len = _printf("%hx", 0);
	len2 = printf("%hx", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.61 -------------------\n");
	len = _printf("%hx", USHRT_MAX);
	len2 = printf("%hx", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.65-------------------\n");
	len = _printf("There is %hx bytes in %hx KB\n", 1024, 1);
	len2 = printf("There is %hx bytes in %hx KB\n", 1024, 1);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.66 -------------------\n");
	len = _printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main.67 -------------------\n");
	 
	len = _printf("%ld", LONG_MAX);
	len2 = printf("%ld", LONG_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n================================================\n");


	 _printf("%s", "Hello Morocco !");
	



	printf("\n------------ -------lu ------------\n");
	_printf("%lu", 1024UL);
	printf("%lu", 1024UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lu", 0UL);
	printf("%lu", 0UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lu", ULONG_MAX);
	printf("%lu", ULONG_MAX);
	printf("\n------------------- main -------------------\n");
	_printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	printf("There is %lu bytes in %lu KB\n", 1024UL, 1UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("\n------------------- lo  -------------------\n");
	printf("\n------------------- main -------------------\n");
	_printf("%lo", 1024UL);
	printf("%lo", 1024UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lo", 0UL);
	printf("%lo", 0UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lo", ULONG_MAX);
	printf("%lo", ULONG_MAX);
	printf("\n------------------- main -------------------\n");
	_printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	printf("There is %lo bytes in %lo KB\n", 1024UL, 1UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("\n-------------------------------------------\n");

	printf("\n-------------------  lx -------------------\n");
	
	printf("\n------------------- main -------------------\n");
	_printf("%lx", 1024UL);
	printf("%lx", 1024UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lx", 0UL);
	printf("%lx", 0UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lx", ULONG_MAX);
	printf("%lx", ULONG_MAX);
	printf("\n------------------- main -------------------\n");
	_printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	printf("There is %lx bytes in %lx KB\n", 1024UL, 1UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);

	printf("\n------------------- LX -------------------\n");
	_printf("%lX", 1024UL);
	printf("%lX", 1024UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lX", 0UL);
	printf("%lX", 0UL);
	printf("\n------------------- main -------------------\n");
	_printf("%lX", ULONG_MAX);
	printf("%lX", ULONG_MAX);
	printf("\n------------------- main -------------------\n");
	_printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	printf("\n------------------- main -------------------\n");
	
	len = _printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	len2 = printf("There is %lX bytes in %lX KB\n", 1024UL, 1UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main -------------------\n");
	len = _printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- main -------------------\n");
	_printf("%hd", -1024);
	printf("%hd", -1024);
	printf("\n------------------- main -------------------\n");
		len = _printf("%ho", 1024);
	len2 = printf("%ho", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main -------------------\n");
		len = _printf("%hx", USHRT_MAX);
	len2 = printf("%hx", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main -------------------\n");
		len = _printf("%hX", 1024);
	len2 = printf("%hX", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main -------------------\n");

	len = _printf("%hu", USHRT_MAX);
	len2 = printf("%hu", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- main -------------------\n");
	len = _printf("%lu - %hu = %hu\n", LONG_MIN, 2048, USHRT_MAX - 2048);
	len2 = printf("%lu - %hu = %hu\n", LONG_MIN, 2048, USHRT_MAX - 2048);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	
printf("\n============================ TASK 9 ==============================\n");



	len = _printf("%6d", 102498402);
	len2 = printf("%6d", 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 2 -------------------\n");

	len = _printf("\n%6d", -102);
	len2 = printf("\n%6d", -102);

	printf("\n%d\n",len);
	printf("%d\n",len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
 
	printf("\n------------------- 3 -------------------\n");
	len = _printf("In the middle %6d of a sentence.\n", 1024);
	len2 = printf("In the middle %6d of a sentence.\n", 1024);

	printf("%d\n",len);
	printf("%d\n",len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 3 -------------------\n");
	_printf("%6d", 1024);
	printf("\n------------------- 5 -------------------\n");
	len = _printf("In the middle %6d of a sentence.\n", 1024);
	len2 = printf("In the middle %6d of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 6 -------------------\n");
	len = _printf("%6i", 102498402);
	len2 = printf("%6i", 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 7  -------------------\n");
	len = _printf("%6i", -102498402);
	len2 = printf("%6i", -102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 8 -------------------\n");
	len = _printf("%6i", 0);
	len2 = printf("%6i", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 9 -------------------\n");
	len = _printf("%6i", 1024);
	len2 = printf("%6i", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 10 -------------------\n");
	len = _printf("%6i", -1024);
	len2 = printf("%6i", -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 11 -------------------\n");
	len = _printf("In the middle %6i of a sentence.\n", 1024);
	len2 = printf("In the middle %6i of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 12 -------------------\n");

	len = _printf("%6u", 102498402);
	len2 = printf("%6u", 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 13 -------------------\n");
	len = _printf("%6u", 0);
	len2 = printf("%6u", 0);

	printf("\n%d\n",len);
	printf("%d\n",len2);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 14 -------------------\n");
	len = _printf("%6u", 1024);
	len2 = printf("%6u", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 15 -------------------\n");
	len = _printf("In the middle %6u of a sentence.\n", 1024);
	len2 = printf("In the middle %6u of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 16 -------------------\n");
	len = _printf("%6o", 102498402);
	printf("\n");
	 len2 = printf("%6o", 102498402); 

	printf("\n%d\n",len);
	printf("%d\n",len2);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 17 -------------------\n");
	len = _printf("%6o", 0);
	len2 = printf("%6o", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 18 -------------------\n");
	len = _printf("%6o", 1024);
	len2 = printf("%6o", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 19 -------------------\n");
	len = _printf("In the middle %6o of a sentence.\n", 1024);
	len2 = printf("In the middle %6o of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 20 -------------------\n");
	len = _printf("%6x", 102498402);
	len2 = printf("%6x", 102498402);

	printf("\n%d\n",len);
	printf("%d\n",len2);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 21 -------------------\n");
	len = _printf("%6x", 0);
	len2 = printf("%6x", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 22 -------------------\n");
	len = _printf("%6x", 102);
	len2 = printf("%6x", 102);

	printf("\n%d\n",len);
	printf("%d\n",len2);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 23 -------------------\n");
	len = _printf("In the middle'%6x'of a sentence.\n", 1024);
	len2 = printf("In the middle'%6x'of a sentence.\n", 1024);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 24 -------------------\n");
	
	len = _printf("%6X", 102498402);
	len2 = printf("%6X", 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 25 -------------------\n");
	len = _printf("%6X", 0);
	len2 = printf("%6X", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 26 -------------------\n");
	len = _printf("%6X", 1024);
	len2 = printf("%6X", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 27 -------------------\n");
	len = _printf("In the middle %6X of a sentence.\n", 1024);
	len2 = printf("In the middle %6X of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 28 -------------------\n");
		len = _printf("%6c", 'A');
	len2 = printf("%6c", 'A');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 29 -------------------\n");
	len = _printf("%6c", 0);
	len2 = printf("%6c", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 30 -------------------\n");

	len = _printf("In the middle %6c of a sentence.\n", 'H');
	len2 = printf("In the middle %6c of a sentence.\n", 'H');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	printf("\n------------------- 31  -------------------\n");
	len = _printf("%6s", "Best School !\n");
	len2 = printf("%6s", "Best School !\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	_printf("%*c", 6, 0);
	printf("\n------------------- 32 -------------------\n");
	len = _printf("%6s", "Hi!\n");
	len2 = printf("%6s", "Hi!\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 33 -------------------\n");
	len = _printf("In the middle %6s of a sentence.\n", "Hey");
	len2 = printf("In the middle %6s of a sentence.\n", "Hey");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 34 -------------------\n");
	len = _printf("%*d", 6, 102498402);
	len2 = printf("%*d", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 35 -------------------\n");
	len = _printf("%*d", 6, -102498402);
	len2 = printf("%*d", 6, -102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 36 -------------------\n");
	len = _printf("%*d", 6, 0);
	len2 = printf("%*d", 6, 0);

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 37 -------------------\n");
	len = _printf("%*d", 6, 1024);
	len2 = printf("%*d", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 38 -------------------\n");
	len = _printf("%*d", 6, -1024);
	len2 = printf("%*d", 6, -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 39 -------------------\n");
	len = _printf("In the middle %*d of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*d of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 40 -------------------\n");
		len = _printf("%*i", 6, 102498402);
	len2 = printf("%*i", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 41 -------------------\n");
	len = _printf("%*i", 6, -102498402);
	len2 = printf("%*i", 6, -102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 42 -------------------\n");
	len = _printf("%*i", 6, 0);
	len2 = printf("%*i", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 43 -------------------\n");
	len = _printf("%*i", 6, 1024);
	len2 = printf("%*i", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 44 -------------------\n");
		len = _printf("%*i", 6, -1024);
	len2 = printf("%*i", 6, -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 45 -------------------\n");
	len = _printf("In the middle %*i of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*i of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 46 -------------------\n");
	len = _printf("%*u", 6, 102498402);
	len2 = printf("%*u", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 47 -------------------\n");
 	len = _printf("%*u", 6, 0);
	len2 = printf("%*u", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n-------------------48  -------------------\n");
		len = _printf("%*u", 6, 1024);
	len2 = printf("%*u", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 49 -------------------\n");
	len = _printf("In the middle %*u of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*u of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 50 -------------------\n");
	len = _printf("%*o\n", 6, 102498402);
	len2 = printf("%*o\n", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 51 -------------------\n");
		len = _printf("%*o", 6, 0);
	len2 = printf("%*o", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 52 -------------------\n");
	len = _printf("%*o", 6, 1024);
	len2 = printf("%*o", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 53 -------------------\n");
	len = _printf("In the middle %*o of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*o of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 54 -------------------\n");
		len = _printf("%*x", 6, 102498402);
	len2 = printf("%*x", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 55 -------------------\n");
	len = _printf("%*x", 6, 0);
	len2 = printf("%*x", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 56 -------------------\n");
	len = _printf("%*x", 6, 1024);
	len2 = printf("%*x", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 57 -------------------\n");
	len = _printf("In the middle %*x of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*x of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 58 -------------------\n");
	len = _printf("%*X", 6, 102498402);
	len2 = printf("%*X", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 59 -------------------\n");
	len = _printf("%*X", 6, 0);
	len2 = printf("%*X", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 60 -------------------\n");
	len = _printf("%*X", 6, 1024);
	len2 = printf("%*X", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n-------------------  61 -------------------\n");
		len = _printf("In the middle %*X of a sentence.\n", 6, 1024);
	len2 = printf("In the middle %*X of a sentence.\n", 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 62 -------------------\n");
	len = _printf("%*c", 6, 'A');
	len2 = printf("%*c", 6, 'A');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 63 -------------------\n");
	len = _printf("%*c", 6, 0);
	len2 = printf("%*c", 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 64 -------------------\n");
	len = _printf("In the middle %*c of a sentence.\n", 6, 'H');
	len2 = printf("In the middle %*c of a sentence.\n", 6, 'H');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 65 -------------------\n");
	len = _printf("%*s", 6, "Best School !\n");
	len2 = printf("%*s", 6, "Best School !\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 66 -------------------\n");
	len = _printf("%*s", 6, "Hi!\n");
	len2 = printf("%*s", 6, "Hi!\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n------------------- 67 -------------------\n");
		len = _printf("In the middle %*s of a sentence.\n", 6, "Hey");
	len2 = printf("In the middle %*s of a sentence.\n", 6, "Hey");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

printf("\n\n====================== TASK 11 =======================\n\n");
 
	printf("\n------------------- 7 -------------------\n");
	len = _printf("%06i", -102498402);
	len2 = printf("%06i", -102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n-------------------  -------------------\n");
		len = _printf("%06i", 102498402);
	len2 = printf("%06i", 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n-------------------  -------------------\n");
	_printf("%06x", 0);
	printf("\n-------------------  -------------------\n");
	len = _printf("%*x", 6, 102498402);
	len2 = printf("%*x", 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("\n-------------------  -------------------\n");
	len = _printf("%8c\n", 'H');
	len2 = printf("%8c\n",  'H');
 
	printf("\n-------------------  -------------------\n");
	len = _printf("%08s\n", "hi");
	len2 = printf("%08s\n",  "hi");
	printf("\n-------------------  -------------------\n");
	len = _printf("%08d\n", 1024);
	len2 = printf("%08d\n", 1024);
	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");

	printf("\n-------------------  -------------------\n");
	
	printf("\n-------------------  -------------------\n");
	printf("\n---------------- fixed ----------------\n");
 
	









	return (0);
}

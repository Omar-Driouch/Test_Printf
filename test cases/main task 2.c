#include <stdio.h>
#include <limits.h>
#include "main.h"


int main()
{

    int res = 10000;
    long l = 10000;
    printf("\nTest case 2\n");
    _printf("%b\n", -10);
    _printf("%b\n", 10);
    
 
    printf("\nTest case 2\n");
    _printf("%b", -1024);
     

    
    printf("\nTest case 3\n");
    _printf("%b", 0);
   

     
    printf("\nTest case 4\n");
    _printf("%b", UINT_MAX);
   

   
   
    printf("\nTest case 5\n");
    _printf("%b", l);
    
 
    
    printf("\nTest case 6\n");
    _printf("There is %b bytes in %b KB\n", 1024, 1);
  

     
    printf("\nTest case 7\n");
    _printf("%b - %b = %b\n", 2048, 1024, 1024);
   

 
    printf("\nTest case 8\n");
    _printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);
   
 
    printf("\nTest case 9\n");
    _printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
    printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);

 
    printf("\nTest case 10\n");
    _printf("uuoxxX%xuoXo\n", 1024);
    printf("uuoxxX%xuoXo\n", 1024);
    return 0;
    }

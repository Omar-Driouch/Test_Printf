#include "main.h"

/**
 * get_right_func - function that selects the correct function
 * @s: pointer to format specifier
 * Return: pointer to the function that takes va_list as its param
 */


int (*get_right_func(const char *s))(va_list)
{
    formatter_t Spe_func[] = {
    {'s', printf_s},
    {'i', printf_i},
    {'d', printf_i},
    {'c', printf_char},
    {'%', printf_char},
    {0, NULL}
};
    int i = 0;

    while (Spe_func[i].spec != 0)
    {
        if (Spe_func[i].spec == *s)
            return (int (*)(va_list))Spe_func[i].func; 
        i++;
    }

    return NULL;
}



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_nbr(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;    
}

int is_space(char c)
{
    if(c == ' ')
        return 1;
    else
        return 0;      

}

int is_letter(char c)
{
    if (c <= 'z' && c >= 'a')
        return (1);
    if (c <= 'Z' && c >= 'A')
        return (1);
    else    
        return 0;
}

int     my_atoi(const char *nptr) // 
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;

    if (!nptr)
        return(0);
    while (!is_nbr(nptr[i]))
    {
        if (nptr[i] == '-')
            sign = -1;
        if (is_letter(nptr[i]))
            return (0);
        i++;
    }
    while (nptr[i] && is_nbr(nptr[i]) && !is_space(nptr[i]))
    {
        result *= 10;
        result += (nptr[i] - 48);
        i++;
    }
    if (sign == -1)
        return(result * sign);
    else
        return(result);   
}


int main() 
{
    struct Test {
        char *input;
        int expected;
        char *name;
    };

    struct Test tests[] = {
        {"123", 123, "Nombre positif"},
        {"-123", -123, "Nombre négatif"},
        {"0", 0, "Zéro"},
        {"   123", 123, "Espaces au début"},
        {"123   ", 123, "Espaces à la fin"},
        {"   123   ", 123, "Espaces au début et à la fin"},
        {"+123", 123, "Plus devant le nombre"},
        {"-0", 0, "Zéro négatif"},
        {"0000123", 123, "Zéros au début"},
        {"-0000123", -123, "Zéros au début avec négatif"},
        {"", 0, "Chaîne vide"},
        {"a123", 0, "Lettre avant le nombre"},
        {"123a", 123, "Lettre après le nombre"},
        {"2147483647", 2147483647, "Limite INT_MAX"},
        {"-2147483648", -2147483648, "Limite INT_MIN"},
        // Ajoutez plus de tests si nécessaire.
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) 
    {
        int result = my_atoi(tests[i].input);
        if (result == tests[i].expected) 
        {
            printf("Test %d: \"%s\" -- Ok (Expected: %d, Got: %d)\n", i+1, tests[i].name, tests[i].expected, result);
        } 
        else 
        {
            printf("Test %d: \"%s\" -- Failure (Expected: %d, Got: %d)\n", i+1, tests[i].name, tests[i].expected, result);
        }
    }
     
}







//https://www.ibm.com/docs/en/i/7.4?topic=functions-atoi-convert-character-string-integer
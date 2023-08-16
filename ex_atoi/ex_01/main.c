#include <stdio.h>
#include <stdlib.h>
#include "my_ft.h"

int is_space(char c)
{
    if(c == ' ')
        return 1;
    else
        return 0;      
}

int is_negative(char c)
{
    if (c == '-')
        return 1;
    else return 0;
}

int ft_atoi_base(char *str, char *base)
{
    if (!str || !base)
        return(0);
        
    int base_len; // Ici on stock lalongeur de base
    int i; // iterateur sur str
    int base_index; // index pour recup la position de la str en int
    int result; 
    int sign; // Pour mofif si negatif

    sign = 1;
    result = 0; // variable qui stockera le resultat
    i = 0;

    while (is_space(str[i]) || is_negative(str[i])) // on skip les espaces et on check les negatif
    {
        if (is_negative(str[i]))
            sign = -1;
        i++;
    }
    
    base_len = my_strlen(base); // on enleve 'i' pour que les signes ou espaces ne soient pas pris en compte.

    while (str[i] && !is_space(str[i])) // Tant que str est vrai et que cest pas un espace on va parcourir str
    {
        base_index = 0; // on reinitialise pour qu'a chaque tour de boucle on ait le bon
        while(base[base_index]) // Boucle pour parcourir la base et comparer avec str
        {
            if (is_space(base[base_index]) || is_negative(base[base_index]) || base[base_index] == '+')
                return 0;
            
            if (str[i] == base[base_index]) 
            {
                result *= base_len;
                result += base_index;
                // Ici on fait comme ATOI, mais on remplace pas la base donnée
            }
            base_index++;
        }
        i++;
    }   
    return (result * sign);
}

int main() 
{
    struct Test 
    {
        char *input;
        char *base;
        int expected;
        char *name;
    };

    struct Test tests[] = 
    {
        {"   ---++0101100100110", "01", -2854, "Binaire"},
        {"-----  FF092", "0123456789ABCDEF", 1044626, "Hexadécimal"},
        {"7D", "0123456789ABCDEF", 125, "Hexadécimal"},
        {"123", "01234567", 83, "Octal"},
        {"456", "0123456789", 456, "Décimal"}, // Test ajouté avec la base 10
        {"-101", "01", -5, "Binaire négatif"},
        {"101", "", 0, "Base vide"},
        {"101", "0", 0, "Base de taille 1"},
        {"101", "01+", 0, "Base avec '+'"},
        {"101", "01-", 0, "Base avec '-'"},
        {"101", "0 1", 0, "Base avec espace"},
        // Ajoutez plus de tests si nécessaire.
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) 
    {
        int result = ft_atoi_base(tests[i].input, tests[i].base);
        if (result == tests[i].expected) 
        {
            printf("Test %d: \"%s\" -- Ok (Expected: %d, Got: %d)\n", i+1, tests[i].name, tests[i].expected, result);
        } 
        else 
        {
            printf("Test %d: \"%s\" -- Failure (Expected: %d, Got: %d)\n", i+1, tests[i].name, tests[i].expected, result);
        }
    }
     
    return 0;
}


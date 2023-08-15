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

int my_atoi(const char *nptr) // 
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

int my_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i); 
}

int pow2(int nb)
{
    int result;
    if (nb == 0)
        return 1;

    result = 1;
    
    while(nb > 0)
    {
        result*=2;
        nb--;
    }
    return result;
}

int ft_atoi_base(char *str, char *base)
{
    int i;
    int result;
    int sign;
    int len;

    i = 0;
    sign = 1;
    result = 0;
    len = my_strlen(str);

    if (!str)
        return(0);
    while (!is_nbr(str[i]))
    {
        if (str[i] == '-')
            sign = -1;
        if (is_letter(str[i]))
            return (0);
        i++;
    }
    if (my_strlen(base) == 10)
        return(my_atoi(str));

    if (my_strlen(base) == 2)
    {
        while (str[i])
        {
            if (str[i] == '1')
            {
                result += pow2(len-1);
            }
            len--;
            i++;
        }
        if (sign == -1)
            return(sign * result);
        else
            return(result);
    }
    return(0);
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
        {"0101100100110", "01", 2854, "Binaire"},
        {"FF", "0123456789ABCDEF", 255, "Hexadécimal"},
        {"7D", "0123456789ABCDEF", 125, "Hexadécimal"},
        {"123", "01234567", 83, "Octal"},
        {"456", "0123456789", 456, "Décimal"}, // Test ajouté avec la base 10
        {"-101", "01", -5, "Binaire négatif"},
        {"101", "", 0, "Base vide"},
        {"101", "0", 0, "Base de taille 1"},
        {"101", "001", 0, "Caractère répété dans la base"},
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


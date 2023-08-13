#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int nb_len(int nb)
{
    int result;

    result = 0;
    if (nb == 0)
        return 1;
    
    if (nb < 0)
        result++;
    while (nb != 0)
    {
        nb = nb / 10;
        result++;
    }
    return result;
}

int     mystrlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char    *myreverse_str(char *str)
{
    int i;
    int len;
    char temp;

    i = 0;
    len = mystrlen(str) - 1;

    while (len > i)
    {
        temp = str[len];
        str[len] = str[i];
        str[i] = temp;
        i++;
        len--;
    }
    return str;
}

char    *myitoa(int number)
{
    char *str_ret;
    int i; 
    int unit;
    int sign;

    i= 0;
    sign = number;
    str_ret = malloc(sizeof(char) * (nb_len(number) + 1));
    if (!str_ret)
        return (NULL);
    if (number == 0)
    {
        str_ret[i] = '0';
        i++;
    }    
    if (number < 0)
        number *= -1;
    while (number != 0)
    {     
        unit = number % 10;
        number = number / 10;
        str_ret[i] = unit + '0';
        i++;
    }
    if (sign < 0)
    {
        str_ret[i] = '-';
        i++;
    }
    str_ret[i] = '\0';
    
    return myreverse_str(str_ret);
}

int     main()
{
    int nb;
    char *to_str;

    nb = -6884;
    to_str = myitoa(nb);
    printf("%s", to_str);

    free (to_str);
}
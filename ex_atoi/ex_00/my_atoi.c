#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     my_atoi(const char *nptr) // 
{
    int number;
    int sign;
    int i;

    number = 0;
    sign = 0;
    i = 0;
    while (nptr[i] >= 9 && nptr[i] <= 13 || nptr[i] == 32)
    {
        i++;
    }
    while (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign++;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        number *= 10;
        number += nptr[i] - '0';
        i++;
    }
    if (!(sign % 2))
        return (number);
    else
        return (-number);
}

int main()
{
    int i;
    char *s;
    s = "968856566666666666666";
    i = my_atoi(s);
    printf("i = %d\n", i);
    return (0);
}



//https://www.ibm.com/docs/en/i/7.4?topic=functions-atoi-convert-character-string-integer
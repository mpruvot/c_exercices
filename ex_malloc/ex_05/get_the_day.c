#include <unistd.h>
#include <stdlib.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str) 
{
    int i;
    i = 0;
    
    while (str[i] != '\0') 
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

char *result_day(int day_index)
{
    if(day_index == 1)
       return ("Monday");
    if(day_index == 2)
       return ("Tuesday");
    if(day_index == 3)
       return ("Wednesday");
    if(day_index == 4)
       return ("Thursday");
    if(day_index == 5)
       return ("Friday");
    if(day_index == 6)
       return ("Saturday");
    if(day_index == 0)
       return ("Sunday");
    else
        return("Error, Wrong input or out of bound ! \n");
}

int get_the_day(int year, int month, int day)
{
int c;
int a;
int m;
int j;

c = (14 - month) / 12;
a = year - c;
m = month + (12 * c) - 2;
j = (day + a + (a / 4) - (a / 100) + (a / 400) + ((31 * m)/12)) % 7;

if (day > 31 || day < 1 )
    return(-1);
if (month > 12 || month < 1)
    return(-2);
if (year > 9999 || year < 1583)
    return (-3);
else
    return j;
}

int main()
{
    int day;

    day = get_the_day(20232, 1, 4);
    my_putstr(result_day(day));
    return 0;

}

// A documenter, à comprendre, et variables à renommer.
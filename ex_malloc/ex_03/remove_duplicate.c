/* Faire une fonction qui supprime les doublons d'un tableau d'int. 
int *remove_duplicate(int *tab, int len)
Ou tab sera un tableau d'int et len sa taille.
Ex: tab = [1,1,3,5,7,4,5,3,3,1]
len = 10 (taille du tableau)
La fonction retournera un NOUVEAU tableau [1,3,5,7,4]
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)

{
    // putnbr
    // taille d'un int positif est plus petit que la taille d'un int negatif
    // nb = int min
    long number;

    number = nb;
    if (number < 0) 
    {
        ft_putchar('-'); 
        number = -number; //
    }
  
    if (number >= 0 && number <= 9)
    {
        ft_putchar(number + '0');   
    }
    if (number > 9)
    {
        ft_putnbr(number / 10);
        ft_putnbr(number % 10);
    }
    
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

int already_exist(int *tab, int index)
{
    int i = 0;

    while (i < index)
    {
        if (tab[i] == tab[index])
            return (1);
        i++;
    }
    return (0);
}

int *remove_duplicate(int *tab, int len)
{

    int i;
    int j;
    int count;
    int *new_tab;

    i = 0;
    count = 0;
    while (i < len)
    {
        if (already_exist(tab, i) == 0)
            count++;
        i++;
    }

    new_tab = malloc(sizeof(int) * count);
    i = 0;
    j = 0;
    
    while (i < len)
    {
        if (already_exist(tab, i) == 0)
        {
            new_tab[j] = tab[i];
            j++;
        }
        i++;
    }
    return new_tab;
}

int main()
{
    int tab[] = {1, 2, 3, 3, 4, 5, 5};
    int *newtab;
    int len;

    len = sizeof(tab)/sizeof(tab[0]);
    newtab = remove_duplicate(tab, len);

       
    free(newtab);
}


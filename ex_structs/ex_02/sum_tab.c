#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;

int sum_tab(t_tab *tab)
{
    int i;
    int sum;

    i = 0;
    sum = 0;

    while (i < tab->len)
    {
        sum += tab->tab[i];
        i++;
    }
    
    return sum;
}

int main()
{
    t_tab *tab; // on defini un ptr tab vers la structure t_tab.
    int result;

    tab = malloc(sizeof(tab)); // on alloue de la memoire sur la heap de la taille de tab;
    if (tab == NULL)
        return(-1);

    tab->len = 4;

    tab->tab = malloc(sizeof(int) * tab->len); // on alloue de la memoire sur la heap de la taille de tab->tab;
    if (tab->tab == NULL)
        return(-2);
        
    tab->tab[0] = 1;
    tab->tab[1] = 1;
    tab->tab[2] = 2;
    tab->tab[3] = 3;

    result = sum_tab(tab);

    printf(" result = %d\n", result);

    free(tab->tab);
    free(tab);
    return(0);
}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;

void sort_ttab(t_tab *tab)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;

    while (i < tab->len)
    {
        j = 0;
        while (j < tab->len - 1)
        {
            if (tab->tab[j + 1] < tab->tab[j])
            {
                temp = tab->tab[j + 1];
                tab->tab[j + 1] = tab->tab[j];
                tab->tab[j] = temp;
            }
            j++;
        }
        i++;
    }
    
}

int main()
{
    t_tab *tab; // on defini un ptr tab vers la structure t_tab.
    int i;

    i =  0;
    tab = malloc(sizeof(t_tab)); // on alloue de la memoire sur la heap de la taille de tab;
    if (tab == NULL)
        return(-1);

    tab->len = 9;

    tab->tab = malloc(sizeof(int) * tab->len); // on alloue de la memoire sur la heap de la taille de tab->tab;
    if (tab->tab == NULL)
        return(-2);
        
    tab->tab[0] = 2;
    tab->tab[1] = 1;
    tab->tab[2] = 5;
    tab->tab[3] = 3;
    tab->tab[4] = 234;
    tab->tab[5] = 24;
    tab->tab[6] = 2454;
    tab->tab[7] = 231;
    tab->tab[8] = 4;

    sort_ttab(tab);

    while (i < tab->len)
    {
        printf("%d ", tab->tab[i]);
        i++;
    }
    
    free(tab->tab);
    free(tab);
    return (0);
}
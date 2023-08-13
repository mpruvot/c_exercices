#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;

int *my_tabcpy(int *src, int *dest, int len) // ici j'ajoute len qui remplacera le \0 pour les chaines de char.
{
    int i;

    i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

t_tab *concate_ttab(t_tab *tab1, t_tab* tab2)
{
    t_tab *new_tab;

    new_tab = malloc(sizeof(t_tab));
    if (new_tab == NULL)
        return (NULL);

    new_tab->len = tab1->len + tab2->len;

    new_tab->tab = malloc(sizeof(int) * (tab1->len + tab2->len));
    if (new_tab->tab == NULL)
        return (NULL);
    
    my_tabcpy
    (tab1->tab, new_tab->tab, tab1->len);
    my_tabcpy
    (tab2->tab, &new_tab->tab[tab1->len], tab2->len);

    return new_tab;
    
}

int main()
{
    t_tab *tab1;
    t_tab *tab2;
    t_tab *newtab_concate;
    int i;

    i = 0;

    tab1 = malloc(sizeof(t_tab));
    if (tab1 == NULL)
        return(-1);

    tab2 = malloc(sizeof(t_tab));
    if (tab2 == NULL)
        return(-2);
    
    tab1->len = 5;
    tab2->len = 5;

    tab1->tab = malloc(sizeof(int) * tab1->len);
    if (tab1->tab == NULL)
        return (-3);
    tab2->tab = malloc(sizeof(int) * tab2->len);
    if (tab2->tab == NULL)
        return (-4);

    tab1->tab[0] = 0;
    tab1->tab[1] = 1;
    tab1->tab[2] = 2;
    tab1->tab[3] = 3;
    tab1->tab[4] = 4;

    tab2->tab[0] = 5;
    tab2->tab[1] = 6;
    tab2->tab[2] = 7;
    tab2->tab[3] = 8;
    tab2->tab[4] = 9;

    newtab_concate = concate_ttab(tab1, tab2);

    printf("newtab = \n");

    while (i < (tab1->len + tab2->len))
    {
        printf("%d ", newtab_concate->tab[i]);
        i++;
    }
    
    free(tab1->tab);
    free(tab2->tab);
    free(tab1);
    free(tab2);
    free(newtab_concate->tab);
    free(newtab_concate);
    return (0);
}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;

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

t_tab *get_unique_tab(t_tab *tab1, t_tab *tab2)
{
    int i;
    int newlen;
    t_tab *new_tab;
    t_tab *uniquetab;

    uniquetab = malloc(sizeof(t_tab));
    if (uniquetab == NULL)
        return (NULL);

    newlen = tab1->len + tab2->len;
    new_tab = concate_ttab(tab1, tab2);

    uniquetab->tab = remove_duplicate(new_tab->tab, newlen);


    free(new_tab->tab);
    free(new_tab);
    return uniquetab;

}

int main()
{
    t_tab *tab1;
    t_tab *tab2;
    t_tab *new_unique_tab;

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
    tab1->tab[3] = 4;
    tab1->tab[4] = 4;

    tab2->tab[0] = 5;
    tab2->tab[1] = 2;
    tab2->tab[2] = 7;
    tab2->tab[3] = 8;
    tab2->tab[4] = 1;

    new_unique_tab = get_unique_tab(tab1, tab2);

    while (i < 6)
    {
        printf("%d ", new_unique_tab->tab[i]);
        i++;
    }
    

    free(tab1->tab);
    free(tab2->tab);
    free(tab1);
    free(tab2);
    free(new_unique_tab);

    return (0);

}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;

int tab_append(t_tab *tab, int new_value)
{
    int new_len;
    int *new_tab; // je crée un nouveau tableau, qui va stocker les valeurs du tab actuel.
    int i;

    i = 0;
    new_len = tab->len + 1;
    new_tab = malloc(sizeof(int) * new_len);
        if (new_tab == NULL)
            return(-1);
    while (i < tab->len)
    {
        new_tab[i] = tab->tab[i];
        i++;
    }
    new_tab[new_len - 1] = new_value;

    free(tab->tab); // ici je libere l'ancien tableau ! car j'avais ( Process 37538: 1 leak for 32 total leaked bytes.)

    tab->tab = new_tab;
    tab->len = new_len;
    // ici je reafecte les valeurs tab que je viens de creer.
    return 0;
}

int main()
{
    t_tab *tab;
    int i;

    i = 0;
    tab = malloc(sizeof(t_tab));
    if (tab == NULL)
        return (-1);

    tab->len = 5;

    tab->tab = malloc(sizeof(int) * tab->len);
    if (tab->tab == NULL)
        return (-2);
    
    tab->tab[0] = 0;
    tab->tab[1] = 1;
    tab->tab[2] = 5;
    tab->tab[3] = 3;
    tab->tab[4] = 4;

    tab_append(tab, 8);

    while (i < tab->len)
    {
        printf("%d", tab->tab[i]);
        i++;
    }
    
    free (tab->tab);
    free(tab);
    return (0);
}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tab // Groupe de variables auquelles on peut acceder de partout.
{
  int *tab;
  int len;
} t_tab;


int tab_pop(t_tab *tab) // renvoyer la bonne taille.

 // Modifie la taille du tableau et retourne le dernier element du nouveau tableau.
{
    tab->len--;
    return (tab->tab[tab->len - 1]);
}

int main()
{
    t_tab *tab; // on defini un ptr tab vers la structure t_tab.
    int last_item;
    int i;

    i =  0;
    tab = malloc(sizeof(t_tab)); // on alloue de la memoire sur la heap de la taille de tab;
    if (tab == NULL)
        return(-1);

    tab->len = 5;

    tab->tab = malloc(sizeof(int) * tab->len); // on alloue de la memoire sur la heap de la taille de tab->tab;
    if (tab->tab == NULL)
        return(-2);
        
    tab->tab[0] = 0;
    tab->tab[1] = 1;
    tab->tab[2] = 5;
    tab->tab[3] = 3;
    tab->tab[4] = 4;

    printf ("tab->len avant tab_pop = %d\n", tab->len);

    last_item = tab_pop(tab);

    printf ("tab->len apres tab_pop = %d\n", tab->len);

    printf("last_item = %d \n", last_item);

    printf("new tab = ");
    while (i < tab->len)
    {
        printf("%d ",tab->tab[i]);
        i++;
    }
    

    free(tab->tab);
    free(tab);
    return (0);
}

//https://stackoverflow.com/questions/17250480/declaring-int-array-inside-struct

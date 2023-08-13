#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
 
int mystrlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char  *mystrcpy(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);

}

char **get_list_name(char *name1, char *name2)
{
    char **name_tab;

    name_tab = malloc(sizeof(char *) * 2); // J'alloue de la memoire pour deux ptrsvers des chaines de char (char*);
        if (name_tab == NULL)
            return (NULL);
    name_tab[0] = malloc(sizeof(char) * mystrlen(name1)+ 1);
        if (name_tab[0] == NULL)
            return (NULL);
    name_tab[1] = malloc(sizeof(char) * mystrlen(name2)+ 1);
        if (name_tab[1] == NULL)
            return (NULL);
    mystrcpy(name1, name_tab[0]);
    mystrcpy(name2, name_tab[1]);

    return name_tab;
}

int main()
{
    char **name_list = get_list_name("Paul", "Marius");

    ft_putstr(name_list[0]);
    ft_putchar('\n');
    ft_putstr(name_list[1]);
    ft_putchar('\n');

    // test pour trouver un char du tab
    ft_putchar(name_list[1][2]);

    free(name_list[0]);
    free(name_list[1]);
    free(name_list);
    return 0;
}

// https://stackoverflow.com/questions/7812805/how-to-malloc-char-table
// https://www.ibm.com/docs/en/developer-for-zos/9.1.1?topic=concepts-memory-allocation
// https://www.youtube.com/watch?v=ZLc_OpzND2c
// https://www.youtube.com/watch?v=t72BzxMAQKs
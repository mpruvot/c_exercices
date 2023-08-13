#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_ft.h"

int toto(int nb)
{
    return(nb + 1);
}

int titi(int nb)
{
    return(nb -1);
}

int operate_on_nb(int nb, int (*pf)(int))
{
    return(pf(nb));
}

int main(int argc, char **argv)
{
    int (*pf)(int);
    
    pf = NULL;
    if (argc == 2)
    {
        if(strcmp(argv[1], "toto") == 0)
            pf = &toto;
    }
    else
        pf = &titi;

    printf("%d\n", operate_on_nb(10, pf));
    return(0);
}


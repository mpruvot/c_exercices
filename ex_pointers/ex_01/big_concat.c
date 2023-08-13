
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void myputstr(char *str)
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

char *big_concat(char **str_list, int len)
{
    char *new_str;
    int i;
    int sum_len;

    i = 0;
    sum_len = 0;

    while (i < len)
    {
        sum_len += mystrlen(str_list[i]);
        i++;
    }
    new_str = malloc(sizeof(char) * sum_len + 1);
    if (!new_str)
        return(NULL);

    i = 0;
    sum_len = 0;

    while (i < len)
    {
        mystrcpy(str_list[i], &new_str[sum_len]);
        sum_len += mystrlen(str_list[i]);
        i++;
    }
    new_str[sum_len] = '\0';
   
    return new_str;
}

int main()
{
    char *strlist[] = {"coucou ", "je ", "suis ", "paul"};
    char *new_str;

    new_str = big_concat(strlist, 4);

    myputstr(new_str);

    free(new_str);
    return (0);
}


        // ressource pour init un tableau de tab
//https://stackoverflow.com/questions/21023605/initialize-array-of-strings ---> *str[]= {"...", "..."};
// https://www.youtube.com/watch?v=t72BzxMAQKs ---> loop malloc

/*     str_list = malloc(sizeof(char*) * len);
        if(str_list == NULL)
            return (NULL);
    while (i < len)
    {
        str_list[i] = malloc(sizeof(char) * mystrlen(str_list[i]) + 1);
        if (str_list[i] == NULL)
            return (NULL);
        i++;
    }
     */
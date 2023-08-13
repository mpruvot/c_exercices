/* Faire une fonction qui concatenate 2 strings.
char *my_strcat(char *str1, char* str2)
Elle devra retourner une nouvelle chaine contenant str1 + str2 
Ex: str1 : "Coucou"
str2 : "je suis Paul"
Retournera Ex "Coucou" et "je suis Paul" -> "Coucouje suis Paul" */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int len;
    len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    return len;
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

char *my_strcpy(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *str1, char* str2)
{
    int len1;
    int len2;
    char *newstr;

    len1 = ft_strlen(str1);
    len2 = ft_strlen(str2);

    newstr = malloc(sizeof(char) * (len1 + len2 + 1));
    if (newstr == NULL)
        return (NULL);

    my_strcpy(str1, newstr);
    my_strcpy(str2, &newstr[len1]);

    return newstr;
}

int main()
{
    char *strcat;

    strcat = my_strcat("Coucou", "Je suis Marius!");
    my_putstr(strcat);
    free(strcat);
    return (0);
}

/* `int my_mini_split(char *str, char **dest)`

str_split est un exo courrant, et parfois super complexe. Ici on va en faire une version simplifiée:
On devra decouper la chaine `str` par les ESPACE (ASCII 32).
Ainsi "Coucou je suis Paul" devient ["Coucou", "je", "suis" "Paul"] (SANS les espaces).
Si il y a plusieurs espaces on les decoupes TOUS. Les espaces peuvent se situer en debut/fin/milieux de chaines.
Quelques exemples:

`"        Toto        " -> ["Toto"]`

`" Test Toto       Test2         " -> ["Test", "Toto", "Test2"]`

Le tableau sera stocké dans dest et la fonction retourne la taille du tableau. */


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
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
 
int mystrlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *mystrcpy(char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);

}

int mycount_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0 ; 

    if (str == NULL || *str == '\0') // si la str est vide (error)
        return 0;
    
    if (*str != ' ')
        count = 1;
    //while str[i]
    //while "espace" i ++
    //if char -> word++
    //     while "char" -> i++
    while (str[i])
    {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
        {
            count++;
        }
        i++;
    }
    return count;
}

char *mycopyword(int index, char *str, char *dest)
{
    int i;

    i = 0;
    while (str[index] != ' ' && str[index] != '\0')
    {   
        dest[i] = str[index];
        i++;
        index++;
    }
    dest[i] = '\0';
    return dest;
}

int my_mini_split(char *str, char **dest) // recoder minisplit
{
    int i;
    int j;
    int wordlen;
    int start;
    int tab_len;

    i = 0;
    j = 0;
    wordlen = 0;
    start = 0;
    tab_len = mycount_words(str);

    while (str[i])
    {
        if (str[i] == ' ' && str[i + 1] != ' ' && wordlen != 0) // ajout de && str[i + 1] != ' '
        {
            dest[j] = malloc(sizeof(char) * wordlen + 1);
            if (dest[j] == NULL)
                return(-2);

            mycopyword(start, str, dest[j]);
            wordlen = 0;
            start = i + 1;
            j++;
        }
        if (str[i] != ' ')
            wordlen++;
        i++;
    }
    if(wordlen != 0)
    {
        dest[j] = malloc(sizeof(char) * wordlen + 1);
        if (dest[j] == NULL)
            return(-2);
        mycopyword(start, str, dest[j]);
        j++;
    }
    dest[j] = NULL;
    return tab_len;
}

int main()
{
    char str[] = "    Hello, je suis     marius,     comment allez vous?    ";
    char **split_str = NULL;
    int i;
    int j;

    i = 0;
    j = 0;

    split_str = malloc(sizeof(char*) * (mycount_words(str) + 1));
    if (split_str == NULL)
        return -1;
    
    my_mini_split(str, split_str);
    
    while (split_str[j])
    {
        myputstr(split_str[j]);
        ft_putchar('\n');
        j++;
    }

    while (split_str[i])
    {
        free(split_str[i]);
        i++;
    }
    
    free (split_str);
}


/* Reproduire un mini comportement de printf. 
char *str_in_str(char *src, char *str);
Dans la string src on cherchera une occurence de "%s" et on la remplacera par le second argument str.
Ex: 
src: "Coucou je suis %s"
str: "Paul"
retournera "Coucou je suis Paul"
Si la string str ne contient pas de %s la fonction devra retourner src. 
Le %s pourra être en début, fin, milieu de string, être présent ou absent. Si il est là il ne sera là qu'une seule fois (pour simplifier, mais si tu te sens  de remplacer toutes les occurrences de "%s", enjoy). 
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Mod_Str
{   
    int index_src;
    int index_str;
    int index_newstring;
    int len_src;
    int len_str;
} Mod_Str;


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

// Fonction qui permet de renvoyer le nomber d'occurences de %s
int count_ps(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '%' && str[i + 1] == 's')
            count ++;
        i++;
    }
    return count;
}

char *str_in_str(char *src, char *str)
{
    Mod_Str Str;
    char *newstring;

    Str.index_src = 0;
    Str.index_str = 0;
    Str.index_newstring = 0;
    Str.len_src = ft_strlen(src) - (2 * count_ps(src));
    Str.len_str = ft_strlen(str) * count_ps(src);
    newstring = malloc(sizeof(char) * (Str.len_src + Str.len_str + 1));
    if (newstring == NULL)
        return (NULL);
    while (src[Str.index_src] != '\0')
    {
        if(src[Str.index_src] == '%' && src[Str.index_src + 1] == 's')
        {
            // Ici je doit trouver une solution pour gerer les %s collés sans espaces.
            Str.index_src += 2;

            while (str[Str.index_str] != '\0')
            {
                newstring[Str.index_newstring] = str[Str.index_str];
                Str.index_str++;
                Str.index_newstring++;
            }
            Str.index_str = 0;
        }
        newstring[Str.index_newstring] = src[Str.index_src];
        Str.index_src++;
        Str.index_newstring++;
    }
    newstring[Str.index_newstring] = '\0';
    return newstring;
}
   
int main ()
{
    char *my_newstring;

    my_newstring = str_in_str("123456%s", "7");
    my_putstr(my_newstring);
    free(my_newstring);
    ft_putchar('\n');
    return(0);
}

//https://stackoverflow.com/questions/26707429/how-c-and-s-works-in-c-language


/* Faire une fonction qui retourne une nouvelle chaine de caractere a l'envers:
char *get_my_reverse_putstr(char *str)
A l'envers:
"Bonjour" -> "ruojnoB"
(Même exo que la dernière fois, mais retourne la nouvelle chaine maintenant).
 */

#include <unistd.h>
#include <stdlib.h>

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

char *get_my_reverse_putstr(char *str)
{
    int i;
    int len;
    char *reverse_str;

    i = 0;
    len = ft_strlen(str);
    reverse_str = malloc(sizeof (char) * (len + 1));
    if (reverse_str == NULL) // si malloc echoue
        return (NULL); // Ne met pas fin au programme !
  
    while (len > 0)
    {
        len--;
        reverse_str[i] = str[len];
        i++;
    }

    reverse_str[i] = '\0';

    return reverse_str;

}

int main()
{
    char *reverse;

    reverse = get_my_reverse_putstr("");
    my_putstr(reverse);
    free(reverse);

    reverse = get_my_reverse_putstr("Bonjour");
    my_putstr(reverse); // 0x1
    free(reverse);

    reverse = get_my_reverse_putstr("0123456789"); //0x2
    my_putstr(reverse);
    free(reverse);
    // FREE
    // trouver plus de tests
    return(0);
}
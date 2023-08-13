/* Faire une fonction qui "chiffre" une chaine de caractere en remplacant chaque caracteres par son caractere + 3 (selon l'alphabet):
ex: a devient d, h devient k, z devient c, y devient b
char *get_my_secret_str(char *str)
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

int is_alphabet(char c)
{
    if(c >= 97 && c <= 122)
        return (0);
    
    if(c >= 65 && c <= 90)
        return (1);
    else
        return (-1);
}

char switch_char(char c, int shift)
{
    if (is_alphabet(c) == 0)
        return ((c - 'a' + shift) % 26 + 'a'); // si shift = 3 et c = z --- (122 - 97 + 3) % 26 + 97 = 99 = c
    else if (is_alphabet(c) == 1)
        return ((c - 'A' + shift) % 26 + 'A');
    else
        return c;

        // https://www.scaler.com/topics/caesar-cipher-program-in-c/
}

char *get_my_secret_str(char *str)
{
    int i;
    int len;
    char *secret_str;
    
    i = 0;
    len = ft_strlen(str);
    secret_str = malloc(sizeof(char) * (len + 1));
    if (secret_str == NULL) // si malloc echoue
        return (NULL);
    while (str[i] != '\0')
    {
        secret_str[i] = switch_char(str[i], 3);
        i++;
    }
    secret_str[i] = '\0';
    return secret_str;
}

int main()
{
    char *secret;

    secret = get_my_secret_str("COUCOU");
    my_putstr(secret);
    free(secret);

    secret = get_my_secret_str("coucou");
    my_putstr(secret);
    free(secret);

    secret = get_my_secret_str("wxyz");
    my_putstr(secret);
    free(secret);

    secret = get_my_secret_str("aJdaOPc");
    my_putstr(secret);
    free(secret);

    secret = get_my_secret_str("WXYZ");
    my_putstr(secret);
    free(secret);

    return(0);
}


#include "utilis.h"
#include <unistd.h>
// Count the occurences of a letter in a file.

int count_letter(int fd, char letter)
{
    int i;
    int ret;
    int count;
    char buffer[20]; // servira a lire le fichier par blocs de 256 octets

    ret = read(fd, buffer, sizeof(buffer)); // read lit 20 octets, ret = 20
    //renvoie des erreurs ? 

    while (ret > 0) // Ici la boucle marche une fois, ou reprend tant que read ne retourne pas 0 c.a.d tant que read n'a pas fini de lire le fichier.
    // read retourne 0 si il a fini de lire le fichier !!!!!
    {
        i = 0; // on reinit. i a 0 pour a chaque fois relire depuis la premiere lettre du buffer.

        while (i < ret)
        {
            if (buffer[i] == letter)
                count++; // ici on modifie directement la variable du main grace au ptr.
            i++;
        }
        ret = read(fd, buffer, sizeof(buffer)); // on continue la lecture. 
        // Si je comprend bien, le file descriptor garde en memoire la ou s'est arrété read? il se met a jour en quelque sorte?
    }   
    return (count);
}
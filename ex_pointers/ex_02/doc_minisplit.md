### Mycountwords
- Cette fonction compte les mots d'une chaine de caractères.
- On check d'abord si la str n'est pas vide, sinon on return 0.
` if (str  ==  NULL  ||  *str  ==  '\0') // 
	return  0; `
- Ensuite si la chainenne commence pas par un espace, on init le count à 1 mot.
- finalement on fait une boucle qui incremente count si :
`(str[i] ==  ' '  &&  str[i  +  1] !=  ' '  &&  str[i  +  1] !=  '\0')`
- la ft retourne count.

### Mycopyword
`char  *mycopyword(int  index,  char  *str,  char  *dest)`

- Celle la, je me suis amusé a la faire, elle prend une parametre une *string, une *dest et un index
- l'idée etait que cette fonction puisse decouper un mot dans une str donnée, à partir d'un emplacement donné.
- on part de l'index qu'on donne a la fonction (le debut d'un mot), et tant quon ne trouve pas un espace ou le caractere NULL, on copie str[index] dans dest[i];
```c
while (str[index] != ' ' && str[index] != '\0')
{
    dest[i] = str[index];
    i++;
    index++;
}
```
### Myminisplit
```c
int  my_mini_split(char  *str,  char  **dest)

{
int  i;
int  j;
int  wordlen;
int  start;
int  tab_len;

i  =  0;
j  =  0;
wordlen  =  0;
start  =  0;
tab_len  =  mycount_words(str);
// tab_len est egal au nb de mots.
while (str[i])
{
if (str[i] == ' '  &&  wordlen  !=  0)
/* 
si on rencontre un espace et que wordlen n'est pas 0(donc qu'il y a un mot a copier)
 */
{
dest[j] =  malloc(sizeof(char) *  wordlen  +  1);
if (dest[j] ==  NULL)
// on alloue de la memoire de la taille du mot + 1 pour NULL
return(-2);
mycopyword(start, str, dest[j]); // On copie immediatement le mot, (le NULL de fin est dans la ft copyword)
wordlen  =  0; // on reinit wordlen à 0 pour reprendre le prochain mot a 0;
start  =  i  +  1; // ici c'est pour skipper l'espace 
j++;
}

if (str[i] !=  ' ') // cette condition est la pour ne pas compter d'espace dans la taille du mot.
wordlen++;
i++;
}

if(wordlen  !=  0) // enfin, on verifie si wordlen contient qq chose et si oui, on alloue un new tab et on copie le dernier mot
{
dest[j] =  malloc(sizeof(char) *  wordlen  +  1);
if (dest[j] ==  NULL)
return(-2);
mycopyword(start, str, dest[j]);
j++;
}

dest[j  +  1] =  NULL; // La j'ai juste lu qu'il fallait mettre un NULL a la fin d'une chaine de tab.

return  tab_len;

}
```


# Defi

## ex_00

`int my_atoi(const char *nptr)`

Recoder atoi ... 

RTFM: http://manpagesfr.free.fr/man/man3/atoi.3.html

## ex_01
`char			*my_itoa(int n)`

Recoder iota ....


# Structures

Pour rappel:
```c
typedef struct s_tab {
  int *tab;
  int len;
} t_tab;
```
**`t_tab` represente une structure qui représente un tableau d'int `tab` et sa taille `len`.**

**`len` sera TOUJOURS égal à la taille de `tab`**

Pour info, que j'ai oublié de t'expliquer.

Quand on a un pointeur sur struct, en terme de syntax:
```c
tab->len
```
 est EGAL à 
```c
(*tab).len
```
Si tu comprends pas hésite pas.


## ex_00
`int tab_pop(t_tab *tab)`

Cette fonction prends en entrée une structure tab et enlève le dernier item de la liste.

Exemple:
```c
// tab->tab = [0,1,2,3,4]
// tab.len = 5
int last_item = tab_pop(tab);
// last_item == 4
// tab->tab = [0,1,2,3]
// tab.len = 4
```

## ex_01

`int tab_append(t_tab *tab, int new_value)`

Cette fonction prend en entrée une structure t_tab et lui ajoute new_value.

Il faut penser a update tab->tab et tab->len

## ex_02
`int sum_tab(t_tab *tab)`

Additionne tous les éléments de la liste et le retourne.
Exemple: 
```c
// tab->tab = [1,1,2,3]
int result = sum_tab(t_tab *tab)
// result = 7
```

## ex_03
`t_tab *concate_ttab(t_tab *tab1, t_tab* tab2)`

Retourne une nouvelle t_tab qui est le resultat de la concatenation de tab1 et tab2.
```c
// tab1->tab = [0,1,2,3]
// tab2->tab = [4,5,6]
// new_tab->tab = [0,1,2,3,4,5,6]
```

## ex_04
`t_tab *get_unique_tab(t_tab *tab1, t_tab *tab2)`
Sans grande surprise ... retourne une nouvelle t_tab contenant les valeur unique entre tab1 et tab2.

## ex_05

`void sort_ttab(t_tab *tab)`

La fonction trie par ordre croissant la t_tab `tab`


# pointeur sur pointeur

Pour facilement tester les chaines de chaines, et pour en avoir sous la main facilement, comprendre argc argv peut etre grandement utile. Ce n'est pas obligatoire, mais ca te servira pour avoir facilement sous la main des `char **`

## ex_00

`char **get_list_name(char *name1, char *name2)`

Retourne un pointeur sur pointeur contenant les deux noms:
```c
char **name_list = get_list_name("Paul", "Marius");
// name_list = ["Paul", "Marius]
```

## ex_01

`char *big_concat(char **str_list, int len)`

`str_list` contient une liste de str et `len` sa taille.
La fonction doit retourner une chaine de charactere contenant la concatenation de toutes les strings.
ex:
```c
// str_list = ["coucou ", "je ", "suis ", "Paul"]
concat_string = big_concat(str_list, 4)
//concat_string = "coucou je suis Paul"
```

## ex_02

`int my_mini_split(char *str, char **dest)`

str_split est un exo courrant, et parfois super complexe. Ici on va en faire une version simplifiée:
On devra decouper la chaine `str` par les ESPACE (ASCII 32).
Ainsi "Coucou je suis Paul" devient ["Coucou", "je", "suis" "Paul"] (SANS les espaces).
Si il y a plusieurs espaces on les decoupes TOUS. Les espaces peuvent se situer en debut/fin/milieux de chaines.
Quelques exemples:

`"        Toto        " -> ["Toto"]`

`" Test Toto       Test2         " -> ["Test", "Toto", "Test2"]`

Le tableau sera stocké dans dest et la fonction retourne la taille du tableau.

# Valable pour tous les futurs exo
Maintenant, chaque dossier d'exo **DEVRA OBLIGATOIREMENT** etre compose de cette structure:
```bash
ex_00
├── Makefile
├── main.c
├── my_function.c
├── my_function.h
├── utils.c
└── utils.h
```

(+- README.md contenant l'énoncé de l'exo pourquoi pas)
Où:
`my_function.c`
Contiendra le code de ta fonction et des fonctions dont elle depend directement.

`utils.c`
Contiendra les fonctions "annexes" du genre si ta un `put_str`, `strlen` etc, bref toutes les fonctions en plus.

`main.c`
Contiendra ta fonction main.

`Makefile`
cf ci-dessous

les `.h`
les prototype de tes fonctions, structures, define etc etc etc

Evidemment, si l'exo ne necessite pas de fichier "utils" n'en crée pas des vides

# MAKEFILE
Creer un makefile qui permet de compiler ton code source.
Il devra implementer au minimum les regles:
- all
- re
- clean
- fclean

# Fichiers
Disclaimer: quand on manipule des fichiers dans un programme, surtout quand on apprend, on évite de le faire sur des fichiers sensible, on a vite fais de supprimer et de faire des bétises dessus.

On oublie pas les droits sur les fichiers: si on fait que lire, ca ne sert a rien de demander les droits en écriture etc etc.


## ex_00
Creer un **programme** qui se nommera apres la compilation (avec un Makefile je rappel) `count_letter` qui prend en parametre le nom d'un fichier ET une lettre.

Ce programme affichera le nombre d'occurence de la lettre dans le fichier.

Ainsi, si toto est un fichier:
```bash
cat toto
Coucou je suis une ligne dans le fichier toto
Coucou je suis la 2eme ligne
./count_letter toto o
6
```
## ex_01
Creer un **programme** qui se nommera apres la compilation (avec un Makefile je rappel) `new_file` qui prend en parametre le nom d'un fichier ET **OPTIONELLEMENT** une string

si le programme est appelé de cette manière
```bash
./new_file toto
```
Alors cela créé un nouveau fichier toto

Si la fonction est appelée:
```bash
./new_file toto "coucou"
```
Alors cela créé un nouveau fichier toto contenant la string "coucou"

## ex_02
Creer un **programme** qui se nommera apres la compilation (avec un Makefile je rappel) `meta` qui prend aucun parametre.

Ce programme est un peu spécial car il affiche .... son code source :) (avant compilation of course)
On considérera qu'on executera toujours ce programme dans le dossier qui contient son code source.


## ex_03
Creer un **programme** qui se nommera apres la compilation (avec un Makefile je rappel) `append_to_file` qui prend en parametre le nom d'un fichier ET une string.

Le programme ajoute a la fin du fichier la string

Ainsi, si toto est un fichier:
```bash
cat toto
Coucou je suis une ligne dans le fichier toto
Coucou je suis la 2eme ligne
./append_to_file toto "\nCette nouvelle string a la fin de toto"
cat toto
Coucou je suis une ligne dans le fichier toto
Coucou je suis la 2eme ligne
Cette nouvelle string a la fin de toto
```

Je serais indulgent sur les saut de ligne, les retours a la ligne etc.


# Valable pour les prochains exos

Toutes les consignes d'avant tiennent toujours (structure de projet, Makefile, etc).
Pour les exo concernant les listes chainées, les noeuds seront:
```c
typedef struct s_list {
  void *content;
  struct s_list *next;
}
```

AUCUNE fonction de doit bugger si la liste est vide.


## ex_00

Creer une fonction `void lstadd_back(t_list **lst, t_list *new)` 

Elle ajoutera new a la fin de la liste.

## ex_01

Creer une fonction `void lstadd_front(t_list **lst, t_list *new)` 

Elle ajoutera new au début de la liste.

## ex_02

Creer une fonction `int lst_count(t_list *lst)`

qui retourne la taille de la liste.

## ex_03

Creer une fonction `void lst_reverse(t_list **lst)`

Qui inversera l'ordre de la liste.

## ex_04

Creer une fonction `void lstdelone(t_list *lst, void (*del)(void *))`

Qui prend en parametre un noeud et le supprime graçe a la fonction del.

## ex_05

Creer une fonction `void lstclear(t_list **lst, void (*del)(void *))`

Qui prend en parametre une liste et la desalloue completement.

## ex_06

Creer une fonction `t_list *convert_int_ptr(int *tab)`
Converti un tableau d'int en une liste chainée ou chaque noeud pointe vers un élément de tab.


## ex_07

Creer une fonction `t_list lst_get_index(t_list *lst, int index)`

Renvoie l'élément a l'index donné. A toi de choisir ce que tu fais si l'index n'existe pas dans la liste.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ft.h"

void print_list(t_list *lst)
{
    t_list * current;
    int i;

    current = lst;
    i = 0;
    while (current)
    {
        printf("Node %d = %d\n", i, (*(int *)current->content)); // Vu que c'est un void* on donne le type
        current = current->next;
        i++;
    }
}

t_list *new_element(int content)
{
    t_list *new_element;
    int *content_ptr;

    content_ptr = malloc(sizeof(int));
    if (!content_ptr)
        return (NULL);
    *content_ptr = content;

    new_element = malloc(sizeof(t_list));
    if (!new_element)
    {
        free(content_ptr);
        return (NULL);
    }
    new_element->content = content_ptr;
    new_element->next = NULL;
    return (new_element);
}

void lstadd_front(t_list **lst, t_list *new)
{
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    new->next = *lst;
    *lst = new;
}

int main()
{
    t_list *lst = NULL;
    t_list *temp = NULL;

    // Ajout d'éléments avec la fonction lstadd_front pour tester
    lstadd_front(&lst, new_element(5));
    lstadd_front(&lst, new_element(10));
    
    print_list(lst); 

    // Boucle de free pour liberer le 'content' et les 'noeuds'
    while (lst)
    {
        temp = lst;
        free(temp->content);
        lst = lst->next;
        free(temp);
    }
    
    return (0);
}
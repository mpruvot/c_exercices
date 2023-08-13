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

void lstadd_back(t_list **lst, t_list *new)
{
    t_list *current;

    current = *lst;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    while (current->next)
    {
        current = current->next;
    }
    current->next = new;
}

int main()
{
    t_list *lst = NULL;
    t_list *temp = NULL;

    // Ajout d'éléments avec la fonction lstadd_back pour tester
    lstadd_back(&lst, new_element(5));
    lstadd_back(&lst, new_element(10));
    lstadd_back(&lst, new_element(0));
    lstadd_back(&lst, new_element(3450));
    lstadd_back(&lst, new_element(2350));
    lstadd_back(&lst, new_element(40));
    lstadd_back(&lst, new_element(244));
    lstadd_back(&lst, new_element(10));
    print_list(lst); // Expected: 5 -> 10 -> 20 -> NULL

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
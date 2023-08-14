#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ft.h"

/* void print_list(t_list *lst)
{
    t_list * current;
    int i;
    if (!lst)
    {
        printf("Nothing to print ! \n");
    }
    
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

t_list *node_at_pos(t_list *lst, int pos)
{
    t_list *current;
    int i;

    current = lst;
    i = 0;
    if (lst == NULL || pos < 0)
        return (NULL);
    while (i < pos)
    {
        current = current->next;
        i++;
    }
    return current;
}

void del(void *content)
{
    free(content);
}

void lstdelone(t_list *lst, void (*del)(void *))
{
    del(lst->content);
    free(lst);
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
    lstadd_back(&lst, new_element(0));
    lstadd_back(&lst, new_element(1));
    lstadd_back(&lst, new_element(2));
    lstadd_back(&lst, new_element(3));
    lstadd_back(&lst, new_element(4));
    lstadd_back(&lst, new_element(5));
    lstadd_back(&lst, new_element(6));
    lstadd_back(&lst, new_element(7));
    
    printf("List before 'del' = \n");
    print_list(lst); 

    printf("List after 'del' = \n");
    lstdelone(lst, del);
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
} */

void print_list(t_list *lst)
{
    t_list * current;
    int i;
    if (!lst)
    {
        printf("Nothing to print ! \n");
    }
    
    current = lst;
    i = 0;
    while (current)
    {
        printf("Node %d = %d\n", i, (*(int *)current->content)); // Vu que c'est un void* on donne le type
        current = current->next;
        i++;
    }
}

void del(void *content)
{
    free(content);
}

void lstdelone(t_list *lst, void (*del)(void *))
{
    del(lst->content);
    free(lst);
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

int main()
{
    t_list *node1;

    node1 = new_element(10);

    print_list(node1);

    lstdelone(node1, del);

    node1 = NULL;

    print_list(node1);



}
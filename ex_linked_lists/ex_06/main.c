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

void del(void *content)
{
    free(content);
}

t_list *convert_int_ptr(int *tab)
{
    t_list *head;
    t_list *current;
    int i;
    int len;

    head = malloc(sizeof(t_list));
    if (!head)
        return(NULL);
        head->next = NULL;
    current = head;
    i = 0;
    len = 5;
   
    while (i < len)
    {
        current->content = &tab[i];

        if (i < len - 1)  // Si ce n'est pas le dernier élément
        {
            current->next = malloc(sizeof(t_list));
            if (!current->next)
                return(NULL);
            current = current->next;
        }
        else
            current->next = NULL;
        i++;
    }
    return(head); 
}

int main() 
{
    
    int tab[] = {1, 2, 3, 4, 5};
    t_list *head = convert_int_ptr(tab);
    t_list *temp = NULL;
    print_list(head);
    
    // Liberation de memoire.
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ft.h"

void print_list(t_list *lst)
{
    t_list *current;
    int i;

    i = 0;
    current = lst;
    if (!lst)
        printf("The list is empty!\n");
    else
    while (current)
    {
        printf("Node %d = %d\n", i, (*(int *)current->content));
        current = current->next;
        i++;
    }
}

void lstadd_front(t_list **lst, t_list *new)
{
    if (!*lst)
        *lst = new;
    else
    {
        new->next = *lst;
        *lst = new;
    } 
}

t_list *new_element(int content)
{
    t_list *new_element;
    int *ptr_content;

    ptr_content = malloc(sizeof(int));
    if (!ptr_content)
        return(NULL);
    *ptr_content = content;
    new_element = malloc(sizeof(t_list));
    if (!new_element)
        return(NULL);
    new_element->content = ptr_content;
    new_element->next = NULL;
    return(new_element);  
}

void del(void *content)
{
    free(content);
}

void lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
  
    while (*lst)
    {
        temp = *lst;
        del(temp->content);
        *lst = (*lst)->next;
        del(temp);
    }
    *lst = NULL;
} 

int main()
{
    t_list *node1 = NULL;
   
    lstadd_front(&node1, new_element(10));
    lstadd_front(&node1, new_element(20));
    lstadd_front(&node1, new_element(30));
    lstadd_front(&node1, new_element(40));
    lstadd_front(&node1, new_element(50));

    printf("List before being cleared = \n\n");
    print_list(node1);
    printf("\n");
    printf("List after being cleared = \n\n");
    lstclear(&node1, del);
    print_list(node1);
    
}
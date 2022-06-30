#include "push_swap.h"


//1- TO ADD ELEMENTS ON A (BOT)------------------------------------------------------------------------------

t_info    *create_node(int data)
{
    t_info    *new;

    new = (t_info *) malloc (sizeof(t_info));
    new->num = data;
    new->Next = NULL;
    return(new);
}

t_info    *ft_add_bot(t_info **head, t_info *new)
{
    t_info    *tmp;

    if (!(*head))
    {
        return new;
    }
    tmp = *head;
    while (tmp->Next != NULL)       
            tmp = tmp->Next;
    tmp->Next = new;
    return (*head);
}
//3- TO ADD ELEMENTS ON A (TOP)---------------------------------------------------------------------------

t_info    *ft_add_top(t_info **head, t_info *new)
{
    t_info    *A;

    if (*head == NULL)
        *head = new;
    else
    {
        A = *head;
        *head = new;
        new->Next = A;
    }
    return (*head);
}

// DELETE FIRST ELEMENT ON A (TOP)---------------------------------------------------------------------

void    ft_delete_t(t_info **head)
{
     t_info *temp;

    if (!(*head))
        return ;
     temp = *head;
     if (temp)
    {
        *head = temp->Next;
        free(temp);
    }
}
// DELETE LASTE ELEMENT ON A (BOT)-----------------------------------------------------------------------

void    ft_delete_b(t_info **head)
{
    t_info    *tmp;
    t_info    *last;

    if (*head != NULL)
    {
        tmp = *head;
        last = *head;
        while (tmp->Next != NULL)
        {
            last = tmp;
            tmp = tmp->Next;
        }
        if (tmp == *head)
            *head = NULL;
        else
            last->Next = NULL;
        free(tmp);
    }
}
/// Print list A-------------------------------------------------------

void    ft_display(t_info *a, char *str)
{
     while(a)
    {
        printf("%s ---- %d\n",str, a->num);
        a = a->Next;
    }
}
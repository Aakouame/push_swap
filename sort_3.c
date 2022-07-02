#include "push_swap.h"

int ft_check_sort(t_info *a)
{
    int nb;

    nb = a->num;
    while (a != NULL)
    {
        if (nb > a->num)
            return (1);
        a = a->Next;
    }
    return (0);
}

int ft_biggest(t_info *head)
{
    int nb;

    nb = head->num;
    while (head != NULL)
    {
        if (nb < head->num)
            nb = head->num;
        head = head->Next;
    }
    return (nb);
}

int ft_size(t_info *a)
{
    int size;

    size = 0;
    while (a != NULL)
    {
        size++;
        a = a->Next;
    }
    return (size);
}


void    ft_sorting (t_info **tmp)
{
    t_info    *head;
    int     size;
    int     min;

    if (!tmp)
        return ;
    head = NULL;
    while((*tmp)->Next != NULL)
    {
        min = ft_smallest(*tmp);
        size = ft_size(*tmp);
        ft_put_top_tmp(tmp, ft_indice(*tmp, min), size);
        ft_push(&head, tmp, "");
    }
    while (head != NULL)
        ft_push(tmp, &head, "");
}

    // int     x;
    // int     m;
    // t_info    *head;
    // int     size;

    // head = a;
    // size = 1;
    // while( head != NULL)
    // {
    // printf("mochkil 1\n");
    //     m = ft_biggest(head);
    //     x = ft_indice(head, m);
    //     size = ft_size(head);
    //     ft_display(head, "head = ");
    //     printf(" indie = %d\n", x);
    //     ft_put_top_tmp(&head, x, ft_size(head));
    //     ft_push(&tmp, &head, "");
    // }
    //     ft_display(a, "final a = ");
int ft_val_indice(t_info *tmp, int indice)
{
    while (indice != 0)
    {
        tmp = tmp->Next;
        indice--;
    }
    return (tmp->num);
}
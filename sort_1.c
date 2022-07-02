#include "push_swap.h"

void    ft_case_1(t_info **a)
{
    ft_swap(a, "sa");
    ft_rotate(a, "ra");
}

void    ft_case_3(t_info **a)
{
    ft_swap(a, "sa");
    ft_rev_rotate(a ,"rra");
}

void    ft_sort_1(t_info  **head)
{
    int i;
    t_info    *tmp;
    int a[3];

    tmp = *head;
    i = 0;
    while (tmp != NULL)
    {
        a[i] = tmp->num;
        tmp = tmp->Next;
        i++;
    }
    if (i == 3)
    {
        if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] < a[2]))
                ft_case_1(head);
        else if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] < a[2]))
            ft_swap(head, "sa");
        else if ((a[0] > a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
            ft_case_3(head);
        else if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] > a[2]))
            ft_rotate(head, "ra");
        else if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
                ft_rev_rotate(head, "rra");
    }
}
void    ft_sort_0(t_info  **head)
{
    if (((*head)->num) > ((*head)->Next->num))
        ft_swap(head, "sa");
}

void    ft_delete_indix(t_info **a, int indix)
{
    int t;

    if (indix > ft_size(*a))
    {
        ft_putendl_fd("error  delete indix !", 1);
        return ;
    }
    t = indix;
    while (indix != 0)
    {
        ft_rotate(a, "");
        indix--;
    }
    ft_delete_t(a);
    while (t != 0)
    {
        ft_rev_rotate(a, "");
        t--;
    }
}
#include "push_swap.h"

//      pa (push a): Take the first element at the top of b and put it at the top of a.
//              Do nothing if b is empty
void    ft_push(t_info **a, t_info **b, char *str)
{
    t_info    *iter;

    iter = *b;
    int tmpb;

    if (!b)
        return ;
    tmpb = (*b)->num;
    if (*a)
    {
        *b = (*b)->Next;
        iter->Next = *a;
        *a = iter;
        ft_putendl_fd(str, 1);
        return ;
    }
    if (*b != NULL)
        *b = (*b)->Next;
    *a = iter;
    iter->Next = NULL;
    // ft_delete_t(b);
    // ft_add_top(a, create_node(tmpb));
    ft_putendl_fd(str, 1);
}
//      ra (rotate a): Shift up all elements of stack a by 1.
//              The first element becomes the last one.
void    ft_rotate(t_info **a , char *str)
{
    int tmp;
    if ((*a)->Next == NULL || !(*a))
        return ;
    tmp = (*a)->num;
    ft_delete_t(a);
    ft_add_bot(a, create_node(tmp));
    if (ft_strlen(str) != 0)
        ft_putendl_fd(str, 1);
}
//  rr : ra and rb at the same time.
void    ft_rr(t_info **a, t_info **b)
{
    if ((*a)->Next != NULL && (*b)->Next != NULL)
    {
        ft_rotate(a, "");
        ft_rotate(b, "");
        ft_putstr_fd("rr\n", 1);
    }
    else if ((*a)->Next != NULL && (*b)->Next == NULL)
        ft_rotate(a, "ra");
    else if ((*a)->Next == NULL && (*b)->Next != NULL)
        ft_rotate(b, "rb");
}
//      rra (reverse rotate a): Shift down all elements of stack a by 1.
//          The last element becomes the first one
void    ft_rev_rotate(t_info **a, char *str)
{
    int n;
    t_info    *tmp;

    if ((*a)->Next == NULL || !(*a))
        return ;
    tmp = *a;
    while (tmp->Next != NULL)
        tmp = tmp->Next;
    n = tmp->num;
    ft_delete_b(a);
    *a = ft_add_top(a, create_node(n));
    if (ft_strlen(str) != 0)
        ft_putendl_fd(str, 1);
}
//      rrr : rra and rrb at the same time.
void    ft_rev_rr(t_info **a, t_info **b)
{
    if ((*a)->Next != NULL && (*b)->Next != NULL)
    {
        ft_rev_rotate(a, "");
        ft_rev_rotate(b, "");
        ft_putendl_fd("rrr", 1);
    }
    else if ((*a)->Next != NULL && (*b)->Next == NULL)
        ft_rev_rotate(a, "rra");
    else if ((*a)->Next == NULL && (*b)->Next != NULL)
        ft_rev_rotate(b, "rrb");
}
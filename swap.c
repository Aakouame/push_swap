#include "push_swap.h"

//             sa (swap a): Swap the first 2 elements at the top of stack a.
//          !        Do nothing if there is only one or no elements          !

void    ft_swap(t_info **a, char *str)
{
    int    tmp1;
    int    tmp2;

    tmp1 = (*a)->num;
    tmp2 = (*a)->Next->num;
    ft_delete_t(a);
    ft_delete_t(a);
    ft_add_top(a, create_node(tmp1));
    ft_add_top(a, create_node(tmp2));
    if (ft_strlen(str) != 0)
        ft_putendl_fd(str, 1);
}

//          ss : sa and sb at the same time.

void    ft_ss(t_info **a, t_info **b)
{
    ft_swap(a, "sa");
    ft_swap(b, "sb");
    ft_putendl_fd("ss", 1);
}
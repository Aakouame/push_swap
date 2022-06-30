#include "push_swap.h"

t_info    *ft_duplicate(t_info *a)
{
    t_info    *iter;
    t_info    *dup;

    iter = a;
    dup = NULL;
    while (iter)
    {
        dup = ft_add_bot(&dup, create_node(iter->num));
        iter = iter->Next;
    }
    return (dup);
}


void    ft_sort_4(t_info **a, t_info **b)
{
    t_info  *tmp;
    int     first[2];
    int     second[2];
    int     c;

    tmp = ft_duplicate(*a);
    ft_display (tmp, "1tmp = ");
    ft_sorting(&tmp);
    ft_display (tmp, "tmp final  = "); // Print
    while((*a)->Next != NULL)
    {
        c = 0;
        first[0] = ft_size(tmp) / 3;
        second[0] = first[0] / 2;
        first[1] = ft_val_indice(tmp, first[0]);
        second[1] = ft_val_indice(tmp, second[0]);
        // printf(" first [0] = %d\nfirst [1] = %d\nsecond [0] = %d\nsecond [1] = %d\n\n\n\n\n", first[0], first[1], second[0], second[1]);
        while (c <= (first[0] + 1))
        {
            if ((*a)->num <= first[1])
            {
                // printf(" BOOOOOOOOOOOOOOOOOO\n\n\n");
                ft_push(b, a, "pb");
                ft_delete_b(&tmp);
                if ((*b)->num <= second[1])
                {
                        ft_rotate(b, "rb");
                }
            }
            else
            {
                ft_rotate(a, "ra");
                // printf("valhaala");
            }
            c++;
        }
    }
    ft_delete_b(&tmp);
    ft_display(*b, "B = ");
    while ((*b) != NULL)
    {
        ft_put_top_b(b ,ft_indice(*b, ft_biggest(*b)), ft_size(*b));
        ft_push(a, b, "pa");
    }
    ft_display(tmp, "tmp    ! = ");

}
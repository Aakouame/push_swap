#include "push_swap.h"

int main (int argc, char ** argv)
{
    t_info    *a;
    t_info    *b;
    int size;
    int  i;

    i = 0;
    if (argc > 1)
    {
            // printf("hey\n");
        size = ft_chck(argv);
            // printf("hey1");
        if (size >= 1) // Check (input errors)!
        {
            // Add numbers on list
            a = ft_add(&a, argv, size);
            b = NULL;
            if (size <= 5)
                ft_sort_2(&a, &b, size);
            else if (size > 5)
                ft_sort_4(&a, &b);
            // write (1, "\n\n", 2);
            // ft_display(a ,"a");
        }
        else
            ft_putstr_fd("error ", 1);
    }
    return (0);
}
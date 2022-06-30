#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

int ft_chck(char **argv);


typedef struct t_info{
    int             num;
    struct t_info     *Next;
}t_info;

t_info    *ft_add_bot(t_info **head, t_info *new);
t_info    *ft_add(t_info **head, char **argv, int size);
void    ft_swap(t_info **a, char *str);
t_info    *ft_add_top(t_info **head, t_info *new);
void    ft_delete_t(t_info **head);
t_info    *create_node(int data);
// void    ft_push(t_info **a, t_info **b);
void    ft_rotate(t_info **a , char *str);
void    ft_rr(t_info **a, t_info **b);
void    ft_delete_b(t_info **head);
void    ft_ss(t_info **a, t_info **b);
void    ft_push(t_info **a, t_info **b, char *str);
void    ft_rev_rotate(t_info **a, char *str);
void    ft_rev_rr(t_info **a, t_info **b);
void    ft_sort_1(t_info  **head);
void    ft_sort_2(t_info **a, t_info **b, int size);
void    ft_sort_2(t_info **a, t_info **b, int size);
int     ft_indice(t_info *a, int nb);
int     ft_smallest(t_info *head);
void    ft_sort_0(t_info  **head);
// void    ft_sort_3(t_info **a, t_info **b, int size);
void    ft_put_top_a(t_info **a, int i, int size);
void    ft_sorting (t_info **tmp);
void    ft_put_top_b(t_info **a, int i, int size);
int ft_size(t_info *a);
int ft_biggest(t_info *head);
void    ft_put_top_tmp(t_info **a, int i, int size);

int ft_val_indice(t_info *tmp, int indice);

void    ft_sort_4(t_info **a, t_info **b);

int ft_check_sort(t_info *a);

void    ft_display(t_info *a, char *str);

t_info    *ft_duplicate(t_info *a);


#endif
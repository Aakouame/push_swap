/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:27:07 by akouame           #+#    #+#             */
/*   Updated: 2022/07/04 20:42:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_info **a, t_info **b, char *str)
{
	t_info	*iter;
	int		tmpb;

	iter = *b;
	if (!(*b))
		return ;
	tmpb = (*b)->num;
	if (*a)
	{
		*b = (*b)->next;
		iter->next = *a;
		*a = iter;
		ft_putendl_fd(str, 1);
		return ;
	}
	if (*b != NULL)
		*b = (*b)->next;
	*a = iter;
	iter->next = NULL;
	ft_putendl_fd(str, 1);
}

void	ft_rotate(t_info **a, char *str)
{
	int	tmp;

	if (!(*a) || (*a)->next == NULL)
		return ;
	tmp = (*a)->num;
	ft_delete_t(a);
	ft_add_bot(a, create_node(tmp));
	if (ft_strlen(str) != 0)
		ft_putendl_fd(str, 1);
}

void	ft_rr(t_info **a, t_info **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rotate(a, "");
		ft_rotate(b, "");
		ft_putstr_fd("rr\n", 1);
	}
}

void	ft_rev_rotate(t_info **a, char *str)
{
	int		n;
	t_info	*tmp;

	if (!(*a) || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	n = tmp->num;
	ft_delete_b(a);
	*a = ft_add_top(a, create_node(n));
	if (ft_strlen(str) != 0)
		ft_putendl_fd(str, 1);
}

void	ft_rev_rr(t_info **a, t_info **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rev_rotate(a, "");
		ft_rev_rotate(b, "");
		ft_putendl_fd("rrr", 1);
	}
}

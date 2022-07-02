/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:27:53 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 15:24:17 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smallest(t_info *head)
{
	int	nb;

	nb = head->num;
	while (head != NULL)
	{
		if (nb > head->num)
			nb = head->num;
		head = head->next;
	}
	return (nb);
}

int	ft_indice(t_info *a, int nb)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (nb == a->num)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

void	ft_put_top_a(t_info **a, int i, int size)
{
	if (i == 1)
		ft_swap(a, "sa");
	else if ((size - i) >= (size / 2))
	{
		while ((i) != 0)
		{
			ft_rotate(a, "ra");
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			ft_rev_rotate(a, "rra");
			i++;
		}
	}
}

void	ft_sort_2(t_info **a, t_info **b, int size)
{
	int	min;
	int	i;

	min = ft_smallest(*a);
	i = ft_indice(*a, min);
	if (ft_check_sort(*a) == 0)
		return ;
	if (size > 3)
	{
		ft_put_top_a(a, i, size);
		ft_push(b, a, "pb");
	}
	min = ft_smallest(*a);
	i = ft_indice(*a, min);
	if (size == 5)
	{
		ft_put_top_a(a, i, size);
		ft_push(b, a, "pb");
	}
	ft_sort_1(a);
	if (size == 5)
	{
		ft_push(a, b, "pa");
		ft_push(a, b, "pa");
	}
	if (size == 4)
		ft_push(a, b, "pa");
	else if (size == 2)
		ft_sort_0(a);
}

void	ft_put_top_tmp(t_info **a, int i, int size)
{
	if (i == 0)
		return ;
	else if ((size - i) >= (size / 2))
	{
		while ((i) != 0)
		{
			ft_rotate(a, "");
			i--;
		}
	}
	else
	{
		while (i != size)
		{
			ft_rev_rotate(a, "");
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:27:47 by akouame           #+#    #+#             */
/*   Updated: 2022/07/04 20:30:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_info *a)
{
	t_info	*h;

	h = a;
	while (h->next != NULL)
	{
		if (h->num > h->next->num)
			return (1);
		h = h->next;
	}
	return (0);
}

int	ft_biggest(t_info *head)
{
	int	nb;

	nb = head->num;
	while (head != NULL)
	{
		if (nb < head->num)
			nb = head->num;
		head = head->next;
	}
	return (nb);
}

int	ft_size(t_info *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

void	ft_sorting(t_info **tmp)
{
	t_info	*head;
	int		size;
	int		min;

	if (!tmp)
		return ;
	head = NULL;
	while ((*tmp)->next != NULL)
	{
		min = ft_smallest(*tmp);
		size = ft_size(*tmp);
		ft_put_top_tmp(tmp, ft_indice(*tmp, min), size);
		ft_push(&head, tmp, "");
	}
	while (head != NULL)
		ft_push(tmp, &head, "");
}

int	ft_val_indice(t_info *tmp, int indice)
{
	while (indice != 0)
	{
		tmp = tmp->next;
		indice--;
	}
	return (tmp->num);
}

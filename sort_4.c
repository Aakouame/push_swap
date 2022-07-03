/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:40 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 17:08:03 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_duplicate(t_info *a)
{
	t_info	*iter;
	t_info	*dup;

	iter = a;
	dup = NULL;
	while (iter)
	{
		dup = ft_add_bot(&dup, create_node(iter->num));
		iter = iter->next;
	}
	return (dup);
}

void	ft_help_s_4(t_info	**a, t_info **b, t_info **tmp, int first[2])
{
	int	pbc;
	int	second[2];
	int	indix;

	second[0] = first[0] / 2;
	pbc = 0;
	second[1] = ft_val_indice(*tmp, second[0]);
	while (pbc <= (first[0]))
	{
		if ((*a)->num <= (first[1] +1))
		{
			indix = ft_indice(*tmp, (*a)->num);
			ft_delete_indix(tmp, indix);
			ft_push(b, a, "pb");
			pbc++;
			if ((*b)->num <= second[1] && ((*a)->num > first[1]))
				ft_rr(a, b);
			else if ((*b)->num <= second[1])
				ft_rotate(b, "rb");
		}
		else
			ft_rotate(a, "ra");
	}
}

void	ft_sort_4(t_info **a, t_info **b)
{
	t_info	*tmp;
	int		first[2];

	tmp = ft_duplicate(*a);
	ft_sorting(&tmp);
	while ((*a)->next != NULL)
	{
		if (ft_size(tmp) < 150)
			first[0] = ft_size(tmp) / 3;
		else
			first[0] = ft_size(tmp) / 6;
		first[1] = ft_val_indice(tmp, first[0]);
		ft_help_s_4(a, b, &tmp, first);
	}
	ft_delete_t(&tmp);
	while ((*b) != NULL)
	{
		ft_put_top_b(b, ft_indice(*b, ft_biggest(*b)), ft_size(*b));
		ft_push(a, b, "pa");
	}
}

void	ft_fre(char **tp)
{
	int	p;

	p = 0;
	while (tp[p] != NULL)
	{
		free (tp[p]);
		p++;
	}
	free (tp);
}

void	ft_delete_stack(t_info *a)
{
	if (a)
	{
		while (a != NULL)
			ft_delete_b(&a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:40 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 15:17:36 by akouame          ###   ########.fr       */
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

void	ft_sort_4(t_info **a, t_info **b)
{
	t_info	*tmp;
	int		first[2];
	int		second[2];
	int		pbc;
	int		indix;

	tmp = ft_duplicate(*a);
	ft_sorting(&tmp);
	while((*a)->next != NULL)
	{
		pbc = 0;
		first[0] = ft_size(tmp) / 6;
		second[0] = first[0] / 2;
		first[1] = ft_val_indice(tmp, first[0]);
		second[1] = ft_val_indice(tmp, second[0]);
		indix = ft_indice(tmp, (*a)->num);
		while (pbc <= (first[0]))
		{
			if ((*a)->num <= (first[1] +1))
			{ 
				indix = ft_indice(tmp, (*a)->num);
				ft_delete_indix(&tmp, indix);
				ft_push(b, a, "pb");
				pbc++;
				if ((*b)->num <= second[1])
				{
					if ((*a)->num > first[1])
						ft_rr(a, b);
					else
						ft_rotate(b, "rb");
				}
			}
			else
				ft_rotate(a, "ra");
		}
	}
	ft_delete_t(&tmp);
	while ((*b) != NULL)
	{
		ft_put_top_b(b ,ft_indice(*b, ft_biggest(*b)), ft_size(*b));
		ft_push(a, b, "pa");
	}
 }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:40:21 by akouame           #+#    #+#             */
/*   Updated: 2022/07/04 20:52:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rr_1(t_info **a, t_info **b)
{
	if (!(*b) || !(*a))
		return ;
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rev_rotate(a, "");
		ft_rev_rotate(b, "");
		ft_putendl_fd("", 1);
	}
}

void	ft_rr_1(t_info **a, t_info **b)
{
	if (!(*b) || !(*a))
		return ;
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rotate(a, "");
		ft_rotate(b, "");
		ft_putstr_fd("", 1);
	}
}

void	ft_ss_1(t_info **a, t_info **b)
{
	if (!(*a) || !(*b) || !((*b)->next) || !((*a)->next))
		return ;
	ft_swap(a, "");
	ft_swap(b, "");
}

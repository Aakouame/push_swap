/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:40:21 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 20:43:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rr_1(t_info **a, t_info **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rev_rotate(a, "");
		ft_rev_rotate(b, "");
		ft_putendl_fd("", 1);
	}
	else if ((*a)->next != NULL && (*b)->next == NULL)
		ft_rev_rotate(a, "");
	else if ((*a)->next == NULL && (*b)->next != NULL)
		ft_rev_rotate(b, "");
}

void	ft_rr_1(t_info **a, t_info **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ft_rotate(a, "");
		ft_rotate(b, "");
		ft_putstr_fd("", 1);
	}
	else if ((*a)->next != NULL && (*b)->next == NULL)
		ft_rotate(a, "");
	else if ((*a)->next == NULL && (*b)->next != NULL)
		ft_rotate(b, "");
}

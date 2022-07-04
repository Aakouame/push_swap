/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:47 by akouame           #+#    #+#             */
/*   Updated: 2022/07/04 20:53:30 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_info **a, char *str)
{
	int	tmp1;

	if (!(*a) || !((*a)->next))
		return ;
	tmp1 = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = tmp1;
	if (ft_strlen(str) != 0)
		ft_putendl_fd(str, 1);
}

void	ft_ss(t_info **a, t_info **b)
{
	if (!(*a) || !(*b) || !((*b)->next) || !((*a)->next))
		return ;
	ft_swap(a, "");
	ft_swap(b, "");
	ft_putendl_fd("ss", 1);
}

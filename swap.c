/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:47 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 16:52:37 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_info **a, char *str)
{
	int	tmp1;

	tmp1 = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = tmp1;
	if (ft_strlen(str) != 0)
		ft_putendl_fd(str, 1);
}

void	ft_ss(t_info **a, t_info **b)
{
	ft_swap(a, "sa");
	ft_swap(b, "sb");
	ft_putendl_fd("ss", 1);
}

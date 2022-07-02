/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:47 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 15:03:55 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_info **a, char *str)
{
	int	tmp1;
	int	tmp2;

	tmp1 = (*a)->num;
	tmp2 = (*a)->next->num;
	ft_delete_t(a);
	ft_delete_t(a);
	ft_add_top(a, create_node(tmp1));
	ft_add_top(a, create_node(tmp2));
	if (ft_strlen(str) != 0)
		ft_putendl_fd(str, 1);
}

void	ft_ss(t_info **a, t_info **b)
{
	ft_swap(a, "sa");
	ft_swap(b, "sb");
	ft_putendl_fd("ss", 1);
}

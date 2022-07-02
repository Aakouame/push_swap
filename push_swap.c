/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:26:58 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 14:47:29 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	int		size;
	int		i;

	i = 0;
	if (argc > 1)
	{
		size = ft_chck(argv);
		if (size >= 1)
		{
			a = ft_add(&a, argv, size);
			b = NULL;
			if (size <= 5)
				ft_sort_2(&a, &b, size);
			else if (size > 5)
				ft_sort_4(&a, &b);
		}
		else
			ft_putstr_fd("error ", 1);
	}
	return (0);
}

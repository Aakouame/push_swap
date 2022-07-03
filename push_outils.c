/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:45 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 16:10:24 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_size(char **argv, char **split, char *dst, int size)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		if (split[0] == NULL)
			return (0);
		while (split[j])
		{
			if (ft_check_dig(split[j]) == 0)
				return (0);
			dst = ft_strjoin(dst, split[j]);
			j++;
			size++;
		}
		free(split);
		i++;
	}
	if (!ft_check_rep(dst))
		return (0);
	free(dst);
	return (size);
}

void	ft_help_s_2(int size, t_info **a, t_info **b, int i)
{
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

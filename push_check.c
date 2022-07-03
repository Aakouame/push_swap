/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:27:57 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 15:53:23 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dig(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
		j++;
	}
	if (j == 10 && (str[0] == '-' && str[10] == '9'))
		return (0);
	if (j == 10 && (str[9] == '8' || str[9] == '9'))
		return (0);
	if (j > 10)
		return (0);
	return (1);
}

int	ft_check_rep(char *dst)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = NULL;
	str = ft_split(dst, ' ');
	while (str[i])
	{
		j = i + 1;
		if (str[j])
		{
			while (str[j])
			{
				if (ft_strncmp(str[i], str[j]) == 0)
					return (0);
				else if (str[i] == str[j])
					return (0);
				j++;
			}
		}
		i++;
	}
	ft_fre(str);
	return (1);
}

int	ft_check_car(char **str)
{
	size_t	i;
	size_t	j;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ')
			j++;
		if (j == ft_strlen(str[i]))
			cpt++;
		i++;
	}
	if (cpt == (i - 1))
		return (1);
	return (0);
}

int	ft_chck(char **argv)
{
	char	*dst;
	char	**split;
	int		size;

	dst = NULL;
	split = NULL;
	size = 0;
	if (ft_check_car(argv))
		return (0);
	size = ft_check_size(argv, split, dst, size);
	free(split);
	free(dst);
	return (size);
}

void	ft_put_top_b(t_info **a, int i, int size)
{
	if (i == 1)
		ft_swap(a, "sb");
	else if ((size - i) <= (size / 2))
	{
		while ((i) < size)
		{
			ft_rev_rotate(a, "rrb");
			i++;
		}
	}
	else
	{
		while (i != 0)
		{
			ft_rotate(a, "rb");
			i--;
		}
	}
}

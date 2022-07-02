/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:10 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 15:41:28 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_put_str(char **argv)
{
	int		i;
	char	*dst;
	char	**split;
	int		j;

	dst = NULL;
	split = NULL;
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			dst = ft_strjoin(dst, split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (dst);
}

t_info	*ft_add(t_info **head, char **argv, int size)
{
	char	*str;
	int		i;
	char	**split;

	i = 0;
	str = ft_put_str(argv);
	split = ft_split(str, ' ');
	while (i < size)
	{
		*head = ft_add_bot(head, create_node(ft_atoi(split[i])));
		i++;
	}
	return (*head);
}

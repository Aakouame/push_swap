/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:10 by akouame           #+#    #+#             */
/*   Updated: 2022/07/03 17:07:48 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_put_str(char **argv, char *dst)
{
	int		i;
	char	**split;
	int		j;

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
	str = NULL;
	str = ft_put_str(argv, str);
	split = ft_split(str, ' ');
	free(str);
	while (i < size)
	{
		*head = ft_add_bot(head, create_node(ft_atoi(split[i])));
		i++;
	}
	ft_fre(split);
	return (*head);
}

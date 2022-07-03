/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@studen2.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07 11:20 by akouame           #+#    #+#             */
/*   Updated: 2022/07 20:27 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_er(char *str)
{
	if (!ft_strncmp("sa\n", str))
		return (0);
	else if (!ft_strncmp("sb\n", str))
		return (0);
	else if (!ft_strncmp("ss\n", str))
		return (0);
	else if (!ft_strncmp("pa\n", str))
		return (0);
	else if (!ft_strncmp("pb\n", str))
		return (0);
	else if (!ft_strncmp("ra\n", str))
		return (0);
	else if (!ft_strncmp("rb\n", str))
		return (0);
	else if (!ft_strncmp("rr\n", str))
		return (0);
	else if (!ft_strncmp("rra\n", str))
		return (0);
	else if (!ft_strncmp("rrb\n", str))
		return (0);
	else if (!ft_strncmp("rrr\n", str))
		return (0);
	return (1);
}

void	ft_operations(t_info **a, t_info **b, char *str)
{
	if (!ft_strncmp("sa\n", str))
		ft_swap(a, "");
	else if (!ft_strncmp("sb\n", str))
		ft_swap(b, "sb");
	else if (!ft_strncmp("ss\n", str))
		ft_ss(a, b);
	else if (!ft_strncmp("pa\n", str))
		ft_push(a, b, "");
	else if (!ft_strncmp("pb\n", str))
		ft_push(b, a, "");
	else if (!ft_strncmp("ra\n", str))
		ft_rotate(a, "");
	else if (!ft_strncmp("rb\n", str))
		ft_rotate(b, "");
	else if (!ft_strncmp("rr\n", str))
		ft_rr_1(a, b);
	else if (!ft_strncmp("rra\n", str))
		ft_rev_rotate(a, "");
	else if (!ft_strncmp("rrb\n", str))
		ft_rev_rotate(b, "");
	else if (!ft_strncmp("rrr\n", str))
		ft_rev_rr_1(a, b);
}

void	ft_check_input(t_info *a, t_info *b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (ft_check_er(input))
		{
			ft_putendl_fd("Error", 1);
			exit(0);
		}
		ft_operations(&a, &b, input);
		free(input);
	}
	if (!ft_check_sort(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	exit(0);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	int		size;
	t_info	*a;
	t_info	*b;

	size = ft_chck(argv);
	a = NULL;
	b = NULL;
	if (size > 0 && argc > 1)
	{
		a = ft_add(&a, argv, size);
		ft_check_input(a, b);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}

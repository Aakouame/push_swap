/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:15:21 by akouame           #+#    #+#             */
/*   Updated: 2021/11/17 19:19:43 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (ft_strlen(s) == 0 || !s)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

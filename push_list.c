/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:28:22 by akouame           #+#    #+#             */
/*   Updated: 2022/07/02 15:40:07 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*create_node(int data)
{
	t_info	*new;

	new = (t_info *) malloc (sizeof(t_info));
	new->num = data;
	new->next = NULL;
	return (new);
}

t_info	*ft_add_bot(t_info **head, t_info *new)
{
	t_info	*tmp;

	if (!(*head))
		return (new);
	tmp = *head;
	while (tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = new;
	return (*head);
}

t_info	*ft_add_top(t_info **head, t_info *new)
{
	t_info	*a;

	if (*head == NULL)
		*head = new;
	else
	{
		a = *head;
		*head = new;
		new->next = a;
	}
	return (*head);
}

void	ft_delete_t(t_info **head)
{
	t_info	*temp;

	if (!(*head))
		return ;
	temp = *head;
	if (temp)
	{
		*head = temp->next;
		free(temp);
	}
}

void	ft_delete_b(t_info **head)
{
	t_info	*tmp;
	t_info	*last;

	if (*head != NULL)
	{
		tmp = *head;
		last = *head;
		while (tmp->next != NULL)
		{
			last = tmp;
			tmp = tmp->next;
		}
		if (tmp == *head)
			*head = NULL;
		else
			last->next = NULL;
		free(tmp);
	}
}

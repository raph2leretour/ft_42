/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:44:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/13 14:19:08 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_max(t_list *lst)
{
	int		max;
	t_list	*head;

	if (!lst)
		return (INT_MIN);
	max = lst->content;
	head = lst;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (lst = head, max);
}

bool	checksortarg(t_list *stocka)
{
	t_list	*head;
	t_list	*stocka_cur;

	head = stocka;
	while (stocka)
	{
		stocka_cur = stocka->next;
		while (stocka_cur)
		{
			if (stocka->content > stocka_cur->content)
				return (stocka = head, true);
			stocka_cur = stocka_cur->next;
		}
		stocka = stocka->next;
	}
	return (lst_clean(&head), false);
}

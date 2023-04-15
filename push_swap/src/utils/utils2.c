/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:44:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/15 17:05:38 by raphael          ###   ########.fr       */
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

int	ft_min(int oldmin, t_list *lst)
{
	int		min;
	t_list	*head;

	if (!lst)
		return (INT_MIN);
	head = lst;
	min = ft_max(lst);
	while (lst)
	{
		if (lst->content < min && lst->content > oldmin)
			min = lst->content;
		lst = lst->next;
	}
	return (lst = head, min);
}

void	convertnumb(int argc, t_list **stocka)
{
	int		i;
	int		min;
	t_list	*head;

	i = 0;
	head = *stocka;
	min = ft_min(INT_MIN, *stocka);
	while (i < argc)
	{
		if ((*stocka)->content == min)
		{
			(*stocka)->numb = i++;
			min = ft_min(min, head);
		}
		*stocka = (*stocka)->next;
		if (!*stocka)
			*stocka = head;
	}
	*stocka = head;
	while (*stocka)
	{
		(*stocka)->content = (*stocka)->numb;
		*stocka = (*stocka)->next;
	}
	*stocka = head;
}

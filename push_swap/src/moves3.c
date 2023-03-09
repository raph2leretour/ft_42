/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:30:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/09 20:48:42 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1, the last element becomes the first one.
t_list	*rra(t_list *stocka)
{
	t_list	*head;
	t_list	*lasta;
	t_list	*lst_next;

	if (ft_lstsize(stocka) < 1)
		return (NULL);
	head = stocka;
	lst_next = stocka->next;
	while (lst_next->next)
	{
		stocka = lst_next;
		lst_next = stocka->next;
	}
	lasta = lst_next;
	stocka->next = NULL;
	lasta->next = head;
	return (lasta);
}

// Shift down all elements of stack b by 1, the last element becomes the first one.
t_list	*rrb(t_list *stockb)
{
	t_list	*head;
	t_list	*lastb;
	t_list	*lst_next;

	if (ft_lstsize(stockb) < 1)
		return (NULL);
	head = stockb;
	lst_next = stockb->next;
	while (lst_next->next)
	{
		stockb = lst_next;
		lst_next = stockb->next;
	}
	lastb = lst_next;
	stockb->next = NULL;
	lastb->next = head;
	return (lastb);
}

// rra and rrb at the same time.
void	rrr(t_list *stocka, t_list *stockb)
{
	rra(stocka, stockb);
	rrb(stocka, stockb);
}

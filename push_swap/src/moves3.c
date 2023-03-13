/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:30:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/13 16:11:21 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_list *stocka, bool log)
{
	t_list	*head;
	t_list	*lasta;
	t_list	*lst_next;

	if (ft_lstsize(stocka) < 1)
		return ;
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
	if (log)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list *stockb, bool log)
{
	t_list	*head;
	t_list	*lastb;
	t_list	*lst_next;

	if (ft_lstsize(stockb) < 1)
		return ;
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
	if (log)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list *stocka, t_list *stockb, bool log)
{
	rra(stocka, stockb, 0);
	rrb(stocka, stockb, 0);
	if (log)
		ft_putstr_fd("rrr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/17 13:14:56 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_list *stocka, bool log)
{
	t_list	*next_element;

	if (ft_lstsize(stocka) < 2)
		return ;
	next_element = stocka->next;
	stocka->next = stocka;
	stocka = next_element;
	if (log)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *stockb, bool log)
{
	t_list	*next_element;

	if (ft_lstsize(stockb) < 2)
		return ;
	next_element = stockb->next;
	stockb->next = stockb;
	stockb = next_element;
	if (log)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list *stocka, t_list *stockb, bool log)
{
	sa(stocka, false);
	sb(stockb, false);
	if (log)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **stocka, t_list **stockb, bool log)

{
	t_list	*headb;

	if (!*stockb)
		return ;
	headb = (*stockb)->next;
	ft_lstadd_front(stocka, ft_lstnew((*stockb)->content));
	free(*stockb);
	*stockb = headb;
	if (log)
		ft_putstr_fd("pb\n", 1);
}

void	pb(t_list **stocka, t_list **stockb, bool log)
{
	t_list	*heada;

	if (!stocka)
		return ;
	heada = (*stocka)->next;
	ft_lstadd_front(stockb, ft_lstnew((*stocka)->content));
	free(*stocka);
	*stocka = heada;
	if (log)
		ft_putstr_fd("pa\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/13 16:16:43 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	sa(stocka, stockb, 0);
	sb(stocka, stockb, 0);
	if (log)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_list *stocka, t_list *stockb, bool log)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return ;
	nextb = stockb->next;
	stockb->next = stocka;
	stockb = nextb;
	if (log)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_list *stocka, t_list *stockb, bool log)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return ;
	nexta = stocka->next;
	stocka->next = stockb;
	stocka = nexta;
	if (log)
		ft_putchar_fd("pb\n", 1);
}

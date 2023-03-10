/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/10 14:19:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1, the first element becomes the last one.
int	ra(t_list *stocka)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return (1);
	nexta = stocka->next;
	ft_lstadd_back(&stocka, stocka);
	stocka = nexta;
	return (0);
}

// Shift up all elements of stack b by 1, the first element becomes the last one.
int	rb(t_list *stockb)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return (1);
	nextb = stockb->next;
	ft_lstadd_back(&stockb, stockb);
	stockb = nextb;
	return (0);
}

// ra and rb at the same time.
int	rr(t_list *stocka, t_list *stockb)
{
	int	test;

	test = ra(stocka, stockb);
	if (test != 0)
		return (1);
	test = rb(stocka, stockb);
	if (test != 0)
		return (1);
	else
		return (0);
}

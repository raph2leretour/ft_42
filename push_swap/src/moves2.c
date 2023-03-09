/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/09 15:58:40 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1, the first element becomes the last one.
t_list	*ra(t_list *stocka)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return (NULL);
	nexta = stocka->next;
	ft_lstadd_back(&stocka, stocka);
	stocka = nexta;
	return (stocka);
}

// Shift up all elements of stack b by 1, the first element becomes the last one.
t_list	*rb(t_list *stockb)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return (NULL);
	nextb = stockb->next;
	ft_lstadd_back(&stockb, stockb);
	stockb = nextb;
	return (stockb);
}

// ra and rb at the same time.
void	rr(t_list *stocka, t_list *stockb)
{
	ra(stocka, stockb);
	rb(stocka, stockb);
}

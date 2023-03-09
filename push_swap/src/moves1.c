/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:17 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a, Do nothing if there is only one or no elements.
t_list	*sa(t_list *stocka)
{
	t_list	*next_element;

	if (ft_lstsize(stocka) < 2)
		return (NULL);
	next_element = stocka->next;
	stocka->next = stocka;
	stocka = next_element;
	return (stocka);
}

// Swap the first 2 elements at the top of stack b, Do nothing if there is only one or no elements.
t_list	*sb(t_list *stockb)
{
	t_list	*next_element;

	if (ft_lstsize(stockb) < 2)
		return (NULL);
	next_element = stockb->next;
	stockb->next = stockb;
	stockb = next_element;
	return (stockb);
}

// sa and sb at the same time.
void	ss(t_list *stocka, t_list *stockb)
{
	sa(stocka, stockb);
	sb(stocka, stockb);
}

// Take the first element at the top of b and put it at the top of a, Do nothing if b is empty.
t_list	*pa(t_list *stocka, t_list *stockb)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return (NULL);
	nextb = stockb->next;
	stockb->next = stocka;
	stockb = nextb;
	return (stockb);
}

// Take the first element at the top of a and put it at the top of b, Do nothing if a is empty.
void pb(t_list *stocka, t_list *stockb)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return (NULL);
	nexta = stocka->next;
	stocka->next = stockb;
	stocka = nexta;
	return (stockb);
}

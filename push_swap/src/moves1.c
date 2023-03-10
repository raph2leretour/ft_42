/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/10 14:18:45 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a, Do nothing if there is only one or no elements.
int	sa(t_list *stocka)
{
	t_list	*next_element;

	if (ft_lstsize(stocka) < 2)
		return (1);
	next_element = stocka->next;
	stocka->next = stocka;
	stocka = next_element;
	return (0);
}

// Swap the first 2 elements at the top of stack b, Do nothing if there is only one or no elements.
int	sb(t_list *stockb)
{
	t_list	*next_element;

	if (ft_lstsize(stockb) < 2)
		return (1);
	next_element = stockb->next;
	stockb->next = stockb;
	stockb = next_element;
	return (0);
}

// sa and sb at the same time.
int	ss(t_list *stocka, t_list *stockb)
{
	int	test;

	test = sa(stocka, stockb);
	if (test != 0)
		return (1);
	test = sb(stocka, stockb);
	if (test != 0)
		return (1);
	else
		return (0);
}

// Take the first element at the top of b and put it at the top of a, Do nothing if b is empty.
int	pa(t_list *stocka, t_list *stockb)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return (1);
	nextb = stockb->next;
	stockb->next = stocka;
	stockb = nextb;
	return (0);
}

// Take the first element at the top of a and put it at the top of b, Do nothing if a is empty.
int pb(t_list *stocka, t_list *stockb)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return (1);
	nexta = stocka->next;
	stocka->next = stockb;
	stocka = nexta;
	return (0);
}

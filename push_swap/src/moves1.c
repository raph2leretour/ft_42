/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/01 13:54:52 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a, Do nothing if there is only one or no elements.
void	sa(t_list *stocka, t_list *stockb)
{
	t_list	*next_list;

	if (ft_lstsize(stocka) < 2)
		return ;
	next_element = stocka->next;
	stocka->next = stocka;
	stocka = next_element;
}

// Swap the first 2 elements at the top of stack b, Do nothing if there is only one or no elements.
void	sb(t_list *stocka, t_list *stockb)
{
	t_list	*next_element;

	if (ft_lstsize(stockb) < 2)
		return ;
	next_element = stockb->next;
	stockb->next = stockb;
	stockb = next_element;
}

// sa and sb at the same time.
void	ss(t_list *stocka, t_list *stockb)
{
	sa(stocka, stockb);
	sb(stocka, stockb);
}

// Take the first element at the top of b and put it at the top of a, Do nothing if b is empty.
void	pa(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stockb) < 1)
		return ;
	t_list	topb_element;
	t_list	next_element;
	t_list	current_element;

	if (!stockb->content)
		return ;
	topb_element = ft_lstnew(stockb->content);
	next_element = stockb->next;
	while (next_element)
	{
		current_element = next_element;
		next_element = next_element->next;
	}
	current_element->next = NULL;
	ft_lstadd_front(&stocka, topb_element);
}

// Take the first element at the top of a and put it at the top of b, Do nothing if a is empty.
void pb(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stocka) < 1)
		return ;
	t_list	topa_element;
	t_list	next_element;
	t_list	current_element;

	if (!stocka->content)
		return ;
	topb_element = ft_lstnew(stocka->content);
	next_element = stocka->next;
	while (next_element)
	{
		current_element = next_element;
		next_element = next_element->next;
	}
	current_element->next = NULL;
	ft_lstadd_front(&stockb, topb_element);
}

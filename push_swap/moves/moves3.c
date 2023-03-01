/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:30:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/01 13:54:59 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1, the last element becomes the first one.
void	rra(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stocka) < 2)
		return ;
	t_list	next_element;
	t_list	current_element;

	if (!stocka->content)
		return ;
	next_element = stocka->next;
	while (next_element->next)
	{
		current_element = next_element;
		next_element = next_element->next;
	}
	ft_lstadd_front(&stocka, next_element);
	current_element->next = NULL;
}

// Shift down all elements of stack b by 1, the last element becomes the first one.
void	rrb(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stockb) < 2)
		return ;
	t_list	next_element;
	t_list	current_element;

	if (!stockb->content)
		return ;
	next_element = stockb->next;
	while (next_element->next)
	{
		current_element = next_element;
		next_element = next_element->next;
	}
	ft_lstadd_front(&stockb, next_element);
	current_element->next = NULL;
}

// rra and rrb at the same time.
void	rrr(t_list *stocka, t_list *stockb)
{
	rra(stocka, stockb);
	rrb(stocka, stockb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/01 13:54:55 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1, the first element becomes the last one.
void	ra(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stocka) < 2)
		return ;
	t_list	topa_element;
	t_list	next_element;
	t_list	current_element;

	if (!stocka->content)
		return ;
	topa_element = ft_lstnew(stocka->content);
	next_element = stocka->next;
	while (next_element)
	{
		current_element = next_element;
		next_element = next_element->next;
	}
	current_element->next = NULL;
	ft_lstadd_back(&stocka, topa_element);
}

// Shift up all elements of stack b by 1, the first element becomes the last one.
void	rb(t_list *stocka, t_list *stockb)
{
	if (ft_lstsize(stockb) < 2)
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
	ft_lstadd_back(&stockb, topb_element);
}

// ra and rb at the same time.
void	rr(t_list *stocka, t_list *stockb)
{
	ra(stocka, stockb);
	rb(stocka, stockb);
}

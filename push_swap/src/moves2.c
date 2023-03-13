/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/13 16:11:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_list *stocka, bool log)
{
	t_list	*nexta;

	if (ft_lstsize(stocka) < 1)
		return ;
	nexta = stocka->next;
	ft_lstadd_back(&stocka, stocka);
	stocka = nexta;
	if (log)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list *stockb, bool log)
{
	t_list	*nextb;

	if (ft_lstsize(stockb) < 1)
		return ;
	nextb = stockb->next;
	ft_lstadd_back(&stockb, stockb);
	stockb = nextb;
	if (log)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list *stocka, t_list *stockb, bool log)
{
	ra(stocka, stockb, 0);
	rb(stocka, stockb, 0);
	if (log)
		ft_putstr_fd("rr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/17 13:21:09 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_list **stocka, bool log)
{
	int		itmp;
	t_list	*ltmp;
	t_list	*ltmp_next;

	if (!*stocka || ft_lstsize(*stocka) < 1)
		return ;
	itmp = (*stocka)->content;
	ltmp = *stocka;
	while (ltmp->next)
	{
		ltmp_next = ltmp->next;
		ltmp->content = ltmp_next->content;
		ltmp = ltmp->next;
	}
	ltmp->content = itmp;
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
	ra(&stocka, false);
	rb(stockb, false);
	if (log)
		ft_putstr_fd("rr\n", false);
}

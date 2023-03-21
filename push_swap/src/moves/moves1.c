/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/21 13:53:17 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_list **stocka, t_list **stockb)

{
	t_list	*headb;

	if (!*stockb)
		return ;
	headb = (*stockb)->next;
	ft_lstadd_front(stocka, ft_lstnew((*stockb)->content));
	free(*stockb);
	*stockb = headb;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stocka, t_list **stockb)
{
	t_list	*heada;

	if (!stocka)
		return ;
	heada = (*stocka)->next;
	ft_lstadd_front(stockb, ft_lstnew((*stocka)->content));
	free(*stocka);
	*stocka = heada;
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_list **stocka)
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
	ft_putstr_fd("ra\n", 1);
}

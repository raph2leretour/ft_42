/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/25 16:02:01 by rtissera         ###   ########.fr       */
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

void	sa(t_list **stocka)
{
	t_list	*lst;
	t_list	*lst_next;

	if (!*stocka || ft_lstsize(*stocka) < 2)
		return ;
	lst = *stocka;
	lst_next = (*stocka)->next;
	lst->next = lst_next->next;
	lst_next->next = lst;
	*stocka = lst_next;
	ft_putstr_fd("sa\n", 1);
}

void	rra(t_list **stocka)
{
	int		i;
	t_list	*head;
	t_list	*lst_last;

	i = ft_lstsize(*stocka);
	head = *stocka;
	lst_last = ft_lstlast(*stocka);
	while (i > 2)
	{
		*stocka = (*stocka)->next;
		i--;
	}
	(*stocka)->next = NULL;
	lst_last->next = head;
	*stocka = lst_last;
	ft_putstr_fd("rra\n", 1);
}

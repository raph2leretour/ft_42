/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:00 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/13 18:24:10 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_last_bit_one(t_list **a, t_list **b, int bit_max)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		tmp = (*a)->content;
		if (((tmp >> bit_max) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	big_sort(t_list *stocka, t_list *stockb)
{
	int	max_num;
	int	bit_max;

	max_num = ft_max(stocka);
	bit_max = 0;
	while (max_num >> bit_max)
	{
		push_last_bit_one(&stocka, &stockb, bit_max);
		while (ft_lstsize(stockb) > 0)
			pa(&stocka, &stockb);
		bit_max++;
	}
	lst_clean(&stocka);
	lst_clean(&stockb);
}

void	push_swap(t_list *stocka)
{
	t_list	*stockb;

	stockb = NULL;
	big_sort(stocka, stockb);
}

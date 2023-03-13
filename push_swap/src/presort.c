/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:05:44 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/13 16:25:22 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	medianificator(t_list *lst, int argc)
{
	int		i;
	int		mediane;
	t_list	*head;

	i = 0;
	head = lst;
	while (i < argc / 2)
	{
		lst = lst->next;
		i++;
	}
	mediane = lst->content;
	return (lst = head, mediane);
}

t_list	*presort(t_list *stocka, t_list *tmp, int argc)
{
	int			i;
	int			mediane;
	t_list		*stockb;
	t_struct	*toprint;

	i = 0;
	mediane = medianificator(tmp, argc);
	while ()
	{
		while (i < argc)
		{
			if (stocka->content > mediane)
				ft_structadd_back(&toprint, ft_structnew(pb(stockb)));
			else
				ft_structadd_back(&toprint, ft_structnew(ra(stocka)));
			if (!toprint)
				return (lst_clean(stocka), lst_clean(stockb), struct_clean(toprint), NULL);
			i++;
		}
		i += mediane;
	}
}

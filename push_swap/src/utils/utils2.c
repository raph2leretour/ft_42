/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:44:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/12 15:55:09 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_max(t_list *lst)
{
	int		max;
	t_list	*head;

	if (!lst)
		return (INT_MIN);
	max = lst->content;
	head = lst;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (lst = head, max);
}

bool	checksortarg(t_list *stocka)
{
	t_list	*head;
	t_list	*stocka_cur;

	head = stocka;
	while (stocka)
	{
		stocka_cur = stocka->next;
		while (stocka_cur)
		{
			if (stocka->content > stocka_cur->content)
				return (stocka = head, true);
			stocka_cur = stocka_cur->next;
		}
		stocka = stocka->next;
	}
	return (lst_clean(&head), false);
}

bool	checkmaxintarg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{

		}
	}
}

{
	int	res;
	int	sig;

	res = 0;
	sig = 1;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if (*nptr == 45)
	{
		sig *= -1;
		nptr++;
	}
	else if (*nptr == 43)
		nptr++;
	while ((*nptr >= 48) && (*nptr <= 57))
	{
		res = (res * 10) + *nptr - 48;
		nptr++;
	}
	return (res * sig);
}

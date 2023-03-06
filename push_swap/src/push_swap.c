/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:00 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/06 21:03:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkarg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][i]) != 1)
			return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*atoi_list(char **argv)
{
	int		i;
	t_list	*stocka;
	t_list	*head;

	i = 1;
	head = ft_lstnew(atoi(argv[i]));
	stocka = head->next;
	while (argv[i])
	{
		stocka = ft_lstnew(atoi(argv[i]));
		stocka = stocka->next;
		i++;
	}
	return (head);
}

int	checksamearg(t_list *stocka)
{
	t_list	*head;
	t_list	*lst_cur;

	head = stocka;
	while (lst->content)
	{
		lst_cur = lst->next
		while (lst_cur->content)
		{
			if (lst->content == lst_cur->content)
				return (lst_clean(stocka), 1);
			lst_cur = lst_cur->next;
		}
		lst = lst->next;
	}
	return (lst = head, 0);
}

void	lst_clean(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}

int	push_swap(t_list *stocka)
{
	char	*moves;
	t_list	*stockb;
}

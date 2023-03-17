/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:06:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/17 13:35:26 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	checkarg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && argv[i][0])
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		if (ft_isdigit(argv[i][j]) != 1)
			return (false);
		i++;
	}
	return (true);
}

t_list	*atoi_list(int argc, char **argv)
{
	int		i;
	t_list	*stocka;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stocka, ft_lstnew(atoi(argv[i])));
		i++;
	}
	return (stocka);
}

bool	checksamearg(t_list *stocka)
{
	t_list	*head;
	t_list	*stocka_cur;

	head = stocka;
	while (stocka)
	{
		stocka_cur = stocka->next;
		while (stocka_cur)
		{
			if (stocka->content == stocka_cur->content)
				return (lst_clean(&stocka), false);
			stocka_cur = stocka_cur->next;
		}
		stocka = stocka->next;
	}
	return (stocka = head, true);
}

void	lst_clean(t_list **lst)
{
	t_list	*lst_next;
	t_list	*lst_current;

	if (!lst || !*lst)
		return ;
	lst_current = *lst;
	while (lst_current)
	{
		lst_next = lst_current->next;
		free(lst_current);
		lst_current = lst_next;
	}
	*lst = NULL;
	return ;
}

void	struct_clean(t_struct *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}

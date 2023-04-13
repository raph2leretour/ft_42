/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:06:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/13 15:22:09 by raphael          ###   ########.fr       */
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
	int			i;
	int			intok;
	long int	checkintmax;
	t_list		*head;
	t_list		*stocka;

	i = 1;
	head = NULL;
	stocka = NULL;
	while (i < argc)
	{
		checkintmax = ft_atoi(argv[i]);
		if (checkintmax > INT_MAX || checkintmax < INT_MIN)
			return (lst_clean(&head), NULL);
		intok = checkintmax;
		ft_lstadd_back(&stocka, ft_lstnew(intok));
		if (!head)
			head = stocka;
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
				return (lst_clean(&head), false);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:11 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/24 14:39:32 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *buf)
{
	t_list	*lst

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->buf = buf;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_lst = ft_lstlast(*lst);
	last_lst->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

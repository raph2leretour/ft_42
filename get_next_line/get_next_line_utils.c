/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:02 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/09 19:37:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *buf)
{
	int		i;
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		lst->buf[i] = buf[i];
		i++;
	}
	lst->buf[i] = '\0';
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

void	clear_old_line(t_list **lst)
{
	int	i;
	int	j;
	int	size_old_line;
	t_list	*lst_next;

	i = 0;
	j = 0;
	size_old_line = linelen(lst);
	if (!*lst)
		return ;
	while ((*lst)->buf[i + size_old_line] == '\0')
	{
		if ((*lst)->next)
			lst_next = (*lst)->next;
		free(*lst);
		if (lst_next)
			*lst = lst_next;
		i += BUFFER_SIZE;
	}
	while (j <= size_old_line)
	{
		(*lst)->buf[i] = (*lst)->buf[i + size_old_line];
		i++;
		j++;
	}
	(*lst)->buf[i] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:18:17 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/09 15:07:13 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line_bonus.h"

t_list	*ft_lstnew(char *buf)
{
	int		i;
	t_list	*lst;

	if (!*buf)
		return (NULL);
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
	int		i;
	int		size_old_line;
	t_list	*lst_next;

	if (!*lst)
		return ;
	size_old_line = linelen(lst, 2);
	while (size_old_line - BUFFER_SIZE > 0
		|| (*lst)->buf[size_old_line] == '\0')
	{
		lst_next = (*lst)->next;
		free(*lst);
		*lst = lst_next;
		if (!(*lst))
			return ;
		size_old_line = linelen(lst, 2);
	}
	i = -1;
	size_old_line = linelen(lst, 1);
	while ((*lst)->buf[size_old_line + i++])
		(*lst)->buf[i] = (*lst)->buf[i + size_old_line];
	(*lst)->buf[i] = '\0';
}

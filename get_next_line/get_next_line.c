/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:24:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/09 16:04:49 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(t_list **lst)
{
	int		i;
	int		size;
	t_list	*lst_current;

	i = 0;
	size = 0;
	lst_current = *lst;
	while (lst_current->buf[i] && lst_current->buf[i] != '\n')
	{
		i++;
		size++;
		if (!lst_current->buf[i])
		{
			lst_current = lst_current->next;
			i = 0;
		}
	}
	return (size);
}

void	*read_error(t_list **lst)
{
	t_list	*lst_next;
	t_list	*lst_current;

	lst_current = *lst;
	while (lst_current)
	{
		lst_next = lst_current->next;
		free(lst_current);
		lst_current = lst_next;
	}
	return (NULL);
}

char	*put_in_line(t_list **lst)
{
	int		i;
	int		j;
	int		size;
	char	*line;
	t_list	*lst_next;

	size = linelen(lst);
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (i <= size)
	{
		line[i] = (*lst)->buf[j];
		i++;
		j++;
		if (!(*lst)->buf[j])
		{
			lst_next = (*lst)->next;
			free((*lst));
			*lst = lst_next;
			j = 0;
		}
	}
	return (line);
}

t_list	*read_line(t_list **lst, int	fd)
{
	int		bytes;
	char	buf[BUFFER_SIZE + 1];

	bytes = 0;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (read_error(lst));
		if (bytes == 0)
			break ;
		ft_lstadd_back(lst, ft_lstnew(buf));
	}
	return (*lst);
}

char	*get_next_line(int fd)
{
	char	*line;
	static t_list	*lst = NULL;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lst)
	{
		lst = read_line(&lst, fd);
		if (!lst)
			return (NULL);
	}
	line = put_in_line(&lst);
	if (!line)
		return (NULL);
	clear_old_line(&lst);
	return (line);
}

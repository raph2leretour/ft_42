/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/30 11:39:37 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			bytes;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	line_start[BUFFER_SIZE + 1];
	t_list		*lst;
	t_list		*lst_next;
	
	if (!fd || (BUFFER_SIZE <= 0))
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
		return (NULL);
	i = 0;
	if (line_start[0] != '\0')
	{
		while (line_start[j] != '\n')
			j++;
		while (line_start[j++] && line_start[j] != '\n')
			i++;
	}
	lst = (NULL);
	ft_lstadd_back(&lst, ft_lstnew(buf));
	while (is_new_line(ft_lstlast(lst)->buf) == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		ft_lstadd_back(&lst, ft_lstnew(buf));
	}
	i += is_new_line(ft_lstlast(lst)->buf) + ((ft_lstsize(lst) - 1) * BUFFER_SIZE);
	j = 0;
	line = malloc(sizeof(char)*(i + 1));
	j = -1;
	while (j++ < ft_lstsize(lst) - 1)
	{
		lst_next = lst->next;
		i = -1;
		while ((i++ < BUFFER_SIZE) && (lst->buf[i] != '\n'))
			line[(j * BUFFER_SIZE) + i] = lst->buf[i];
		line[(j * BUFFER_SIZE) + i] = '\n';
		line[(j * BUFFER_SIZE) + i + 1] = '\0';
		free(lst);
		lst = lst_next;
	}
	i = -1;
	while (i++ <= BUFFER_SIZE)
		line_start[i] = ((char *)buf)[i];
	line_start[i] = '\0';
	return (line);
}

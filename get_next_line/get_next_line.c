/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/30 17:00:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*miniline(char *start_line, int i)
{
	int		j;
	char	*line;

	j = -1;
	line = malloc(sizeof(char) * (i + 1));
	while (j++ <= i)
		line[j] = start_line[j];
	line[j] = '\0';
	return (line);
}

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
	return (-1);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			bytes;
	int			decalage;
	int			len_word;
	int			len_lst;
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
	j = 0;
	if (line_start[0] != '\0')
	{
		while (line_start[j] != '\n')
			j++;
		while (line_start[j++] && line_start[j] != '\n')
			i++;
		if (line_start[j] == '\n')
			return (miniline(line_start, i));
	}
	if ((i == BUFFER_SIZE) && (line_start[BUFFER_SIZE] == '\n'))
	{
		i = 0;
		line_start[0] = '\0';
	}
	lst = (NULL);
	ft_lstadd_back(&lst, ft_lstnew(buf));
	while (is_new_line(ft_lstlast(lst)->buf) == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		ft_lstadd_back(&lst, ft_lstnew(buf));
	}
	i += is_new_line(ft_lstlast(lst)->buf) + ((ft_lstsize(lst) - 1) * BUFFER_SIZE);
	line = malloc(sizeof(char)*(i + 1));
	len_word = i + 1;
	decalage = 0;
	if (line_start[0] != '\0')
	{
		while (decalage + is_new_line(line_start) + 1< BUFFER_SIZE)
		{
			line[decalage] = line_start[decalage + is_new_line(line_start) + 1];
			decalage++;
		}
	}
	j = -1;
	len_lst = ft_lstsize(lst) - 1;
	while (j++ < len_lst)
	{
		lst_next = lst->next;
		i = -1;
		while ((i++ < BUFFER_SIZE) && (lst->buf[i] != '\n'))
			line[decalage + (j * BUFFER_SIZE) + i] = lst->buf[i];
		free(lst);
		lst = lst_next;
	}
	line[len_word - 1] = '\n';
	line[len_word] = '\0';
	i = -1;
	while (i++ <= BUFFER_SIZE)
		line_start[i] = ((char *)buf)[i];
	line_start[i] = '\0';
	return (line);
}

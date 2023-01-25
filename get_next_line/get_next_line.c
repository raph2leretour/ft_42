/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/25 03:56:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	int			k;
	int			bytes;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	t_list		*lst;
	t_list		*lst_next;

	if (!fd || (BUFFER_SIZE <= 0))
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
		return (NULL);
	printf("buf:%s", buf);
	lst = (NULL);
	ft_lstadd_back(&lst, ft_lstnew(buf));
	while (is_new_line(ft_lstlast(lst)->buf) == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		printf("buf:%s\n", buf);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		ft_lstadd_back(&lst, ft_lstnew(buf));
	}
	i = is_new_line(ft_lstlast(lst)->buf) + ((ft_lstsize(lst) - 1) * BUFFER_SIZE);
	line = malloc(sizeof(char)*(i + 1));
	j = -1;
	while (j++ < ft_lstsize(lst) - 1)
	{
		lst_next = lst->next;
		k = -1;
		while ((k++ < BUFFER_SIZE) && (lst->buf[k] != '\n'))
			line[(j * BUFFER_SIZE) + k] = lst->buf[k];
		line[(j * BUFFER_SIZE) + k] = '\n';
		line[(j * BUFFER_SIZE) + k + 1] = '\0';
		free(lst);
		lst = lst_next;
	}
	return (line);
}

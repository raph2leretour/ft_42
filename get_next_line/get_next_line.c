/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/23 18:49:37 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *str)
{
	int	i;

	i = -1;
	while (str[i++])
		if (str[i] == '\n')
			return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (!fd || (BUFFER_SIZE <= 0))
		return (NULL);
	ft_lstnew()
	while (is_new_line(lst->buf))
	{
		read(fd, lst->buf, BUFFER_SIZE);
	}
}

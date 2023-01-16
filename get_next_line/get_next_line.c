/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/16 17:39:59 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			len;
	char		*line;
	static char	*bank;
	void		buff[BUFFER_SIZE];

	if !fd
		return (NULL);
	read (fd, buff, BUFFER_SIZE);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (onlybuff(buff), i);
		i++;
	}
	ft_lstnew(buff);
}

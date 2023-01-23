/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/23 14:04:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	void		*buff;
	char		*line;
	static char	stash[1024];

	if ((fd == -1) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	while (stash[i] != '\n')
	{
		if (read(fd, buff, BUFFER_SIZE) == -1)
			return (NULL);
		j = 0;
		while ((((char *)buff)[j + 1] != '\n') && ((char *)buff)[j] && stash[i])
		{
			stash[i] = ((char *)buff)[j];
			j++;
			i++;
		}
	}
	line = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

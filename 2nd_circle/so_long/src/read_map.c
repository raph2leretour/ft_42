/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:09 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/20 14:18:45 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_error(int fd, char *s)
{
	close(fd);
	error(s);
}

void	close_free_error(int fd, char *s1, char *s2)
{
	free(s1);
	close_error(fd, s2);
}

t_map	read_map(int map_fd)
{
	char			*line;
	char			*c_map;
	t_map			map;

	line = get_next_line(map_fd);
	if (!line)
		close_error(map_fd, "Empty Map\n");
	map.x = 0;
	map.y = ft_strlen(line) - 1;
	while (line)
	{
		if (map.x == 0)
			c_map = ft_substr(line, 0, ft_strlen(line));
		else
			c_map = free_strjoin(c_map, line);
		free(line);
		line = get_next_line(map_fd);
		map.x++;
	}
	free(line);
	if (map.x == 0)
		close_free_error(map_fd, c_map, "Empty Map\n");
	map.map = ft_split(c_map, '\n');
	map.mv_nb = 0;
	return (free(c_map), map);
}

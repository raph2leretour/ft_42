/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:09 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/07 17:26:43 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	read_map(int map_fd)
{
	char			*line;
	char			*c_map;
	t_map			map;

	line = get_next_line(map_fd);
	if (!line)
		error("Empty File\n");
	map.x_max = 0;
	map.y_max = ft_strlen(line) - 1;
	while (line)
	{
		if (map.x_max == 0)
			c_map = ft_substr(line, 0, ft_strlen(line));
		else
			c_map = ft_strjoin(c_map, line);
		free(line);
		line = get_next_line(map_fd);
		map.x_max++;
	}
	if (map.x_max == 0)
		error("Empty Map\n");
	map.map = ft_split(c_map, '\n');
	close (map_fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:09 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/07 15:25:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	read_map(char *map_path)
{
	int				map_fd;
	char			*line;
	char			*c_map;
	t_map			map;
	unsigned int	y;

	map.path = map_path;
	map_fd = open(map.path, O_RDONLY, -777);
	line = get_next_line(map_fd);
	//mettre substr en fait
	ft_strlcpy(c_map, line, ft_strlen(line));
	while (line)
	{
		c_map = ft_strjoin(c_map, line);
		free(line);
		line = get_next_line(map_fd);
	}
	map.map = ft_split(c_map, '\n');
	close (map_fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:28:06 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/02 11:39:13 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_map_path(char *map_path)
{
	if (!ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4))
		return (true);
	return (false);
}

bool	check_line_content(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
			return (false);
		i++;
	}
	return (true);
}

bool	check_map_shape(int map_fd)
{
	char			*line;
	unsigned int	x;
	unsigned int	y;
	unsigned int	witness_y;

	x = 0;
	witness_y = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		if (x == 1)
			witness_y = y;
		y = 0;
		while (line[y])
			y++;
		if ((y < 3) || (x > 0 && witness_y != y)
			|| !check_line_content(line))
			return (free(line), false);
		free(line);
		line = get_next_line(map_fd);
		x++;
	}
	if (x < 3)
		return (free(line), false);
	return (free(line), true);
}

bool	check_map(char *map_path)
{
	int	map_fd;

	if (!check_map_path(map_path))
		return (false);
	map_fd = open(map_path, O_RDONLY, 0777);
	if (!check_map_shape(map_fd))
		return (close(map_fd), false);
	close(map_fd);
	return (true);
}

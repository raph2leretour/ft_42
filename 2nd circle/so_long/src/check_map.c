/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:28:27 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/01 08:53: by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// bool	check_map_path(char *map_path)
// {
// }

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
		if ((y < 3) || (x > 1 && witness_y != y))
			return (free(line), false);
		free(line);
		line = get_next_line(map_fd);
		x++;
	}
	if (x < 3)
		return (free(line), false);
	return (free(line), true);
}

// bool	check_endable(int map_fd)
// {
// }

bool	check_map(char *map_path)
{
	int	map_fd;

	map_fd = open(map_path, O_RDONLY, 0777);
	if (!check_map_shape(map_fd))
		return	(false);
	close(map_fd);
	return (true);
}

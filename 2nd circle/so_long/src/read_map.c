/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:09 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/05 18:14:14 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	read_map(int map_fd)
{
	t_map		map;
	unsigned int	y;

	map.x_max = 0;
	map.map[map.x_max] = get_next_line(map_fd);
	while (map.map[map.x_max])
	{
		if (map.x_max == 0)
			map.y_max = ft_strlen(map.map[map.x_max]) - 1;
		y = 0;
		while (map.map[map.x_max])
			y++;
		y--;
		if (y < 3 || (map.x_max > 0 && map.y_max != y)
			|| !check_line_content(map.map[map.x_max]))
			return (clear(map.map), map);
		map.x_max++;
		map.map[map.x_max] = get_next_line(map_fd);
	}
	if (map.x_max < 3)
		return (clear(map.map), map);
	return (map);
}

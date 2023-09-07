/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:28:06 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/07 18:22:23 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_line_content(t_map *map, char *line)
{
	unsigned int	y;

	y = 0;
	if (line[y] && line[y] != '1')
		error("Map Muste Be Surrounded By Walls\n");
	while (line[y + 1])
	{
		if (line[y] == '1' || line[y] == '0')
			y += 0;
		else if (line[y] == 'P')
			(*map).cP++;
		else if (line[y] == 'E')
			(*map).cE++;
		else if (line[y] == 'C')
			(*map).cC++;
		else
			error("Invalid Character\n");
		y++;
	}
	if (line[y] != '1')
		error("Map Muste Be Surrounded By Walls\n");
}

void	check_map_content(t_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	map.cE = 0;
	map.cP = 0;
	map.cC = 0;
	while (map.map[x])
	{
		if (x == 0 || x == map.x_max)
		{
			y = 0;
			while (map.map[x][y])
			{
				if (map.map[x][y] != '1')
					error("Map Must Be Surrounded By Walls\n");
				y++;
			}
		}
		else
			check_line_content(&map, map.map[x]);
		x++;
	}
	if (map.cC < 1 || map.cP != 1 || map.cE != 1)
		error("Map Must Contain 1 E, At Least 1 C, And 1 P\n");
}

void	check_map_shape(t_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (map.map[x])
	{
		y = 0;
		while (map.map[x][y])
			y++;
		if (x > 0 && map.y_max != y)
			error("Map Is Not Rectangular\n");
		x++;
	}
}

void	check_map(t_map map)
{
	if (map.x_max < 3 || map.y_max < 3)
		error("Map Is Too Small\n");
	check_map_shape(map);
	check_map_content(map);
}

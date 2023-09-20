/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:28:06 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/20 15:48:25 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line_content(t_map *map, char *line)
{
	unsigned int	y;

	y = 0;
	while (line[y + 1])
	{
		if ((y == 0 && line[y] != '1') || (y == map->y && line[y] != '1'))
		{
			clear(map->map);
			error("Map Muste Be Surrounded By Walls\n");
		}
		if (line[y] == '1' || line[y] == '0')
			y += 0;
		else if (line[y] == 'P')
			map->cp++;
		else if (line[y] == 'E')
			map->ce++;
		else if (line[y] == 'C')
			map->cc++;
		else
		{
			clear(map->map);
			error("Invalid Character\n");
		}
		y++;
	}
}

void	check_map_content(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	map->ce = 0;
	map->cp = 0;
	map->cc = 0;
	while (map->map[x])
	{
		if (x == 0 || x == map->x - 1)
		{
			y = 0;
			while (map->map[x][y])
			{
				if (map->map[x][y] != '1')
					clearror(map->map, "Map Must Be Surrounded By Walls\n");
				y++;
			}
		}
		else
			check_line_content(map, map->map[x]);
		x++;
	}
	if (map->cc < 1 || map->cp != 1 || map->ce != 1)
		clearror(map->map, "Map Must Contain 1 E, At Least 1 C, And 1 P\n");
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
		if (x > 0 && map.y != y)
		{
			clear(map.map);
			error("Map Is Not Rectangular\n");
		}
		x++;
	}
}

void	check_map_possible(t_map *map)
{
	t_map			c_map;

	c_map = mapcpy(map);
	if (!c_map.map)
		clearror(map->map, "Cannot Copy The Map\n");
	findstart(map);
	if (map->map[map->p_x][map->p_y - 1] == '1'
		|| map->map[map->p_x - 1][map->p_y] == '1'
		|| map->map[map->p_x][map->p_y + 1] == '1'
		|| map->map[map->p_x + 1][map->p_y] == '1')
	{
		clear(c_map.map);
		clear(map->map);
		error("Map Is Not Finishable\n");
	}
	c_map = findaway(c_map, map->p_x, map->p_y);
	if (c_map.cc != map->cc || c_map.ce != map->ce)
	{
		clear(c_map.map);
		clear(map->map);
		error("Map Is Not Finishable\n");
	}
	clear(c_map.map);
}

void	check_map(t_map *map)
{
	if (!(map->x >= 3 && map->y >= 5)
		&& !(map->x >= 5 && map->y >= 3))
	{
		clear(map->map);
		error("Map Is Too Small\n");
	}
	check_map_shape((*map));
	check_map_content(map);
	check_map_possible(map);
}

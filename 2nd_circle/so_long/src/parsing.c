/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:32:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 18:24:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*next_line_get(t_map *map, t_map c_map)
{
	unsigned int	len;

	len = ft_strlen((*map).map[c_map.x]);
	return (ft_substr((*map).map[c_map.x], 0, len));
}

t_map	mapcpy(t_map *map)
{
	char			*line;
	char			*c_line;
	t_map			c_map;

	c_map.x = 0;
	line = next_line_get(map, c_map);
	if (!line)
		clearror((*map).map, "Cannot Copy An Empty Map\n");
	while ((*map).map[c_map.x])
	{
		if (c_map.x == 0)
			c_line = ft_substr(line, 0, ft_strlen(line));
		else
			c_line = ft_strjoin(c_line, line);
		c_line = ft_strjoin(c_line, "\n");
		free(line);
		line = next_line_get(map, c_map);
		c_map.x++;
	}
	c_map.map = ft_split(c_line, '\n');
	c_map.cc = 0;
	c_map.ce = 0;
	free(line);
	free(c_line);
	return (c_map);
}

void	findstart(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 1;
	while ((*map).map[x])
	{
		y = 1;
		while ((*map).map[x][y])
		{
			if ((*map).map[x][y] == 'P')
			{
				(*map).p_x = x;
				(*map).p_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

t_map	findaway(t_map map, unsigned int x, unsigned int y)
{
	if (map.map[x] && map.map[x][y - 1]
		&& map.map[x][y - 1] != '2' && map.map[x][y - 1] != '1')
	{
		map = drop(map, x, y - 1);
	}
	if (map.map[x - 1] && map.map[x - 1][y]
		&& map.map[x - 1][y] != '2' && map.map[x - 1][y] != '1')
	{
		map = drop(map, x - 1, y);
	}
	if (map.map[x] && map.map[x][y + 1]
		&& map.map[x][y + 1] != '2' && map.map[x][y + 1] != '1')
	{
		map = drop(map, x, y + 1);
	}
	if (map.map[x + 1] && map.map[x + 1][y]
		&& map.map[x + 1][y] != '2' && map.map[x + 1][y] != '1')
	{
		map = drop(map, x + 1, y);
	}
	return (map);
}

t_map	drop(t_map map, unsigned int x, unsigned int y)
{
	if (map.map[x][y] == 'E')
		map.ce++;
	else if (map.map[x][y] == 'C')
		map.cc++;
	map.map[x][y] = '2';
	return (findaway(map, x, y));
}

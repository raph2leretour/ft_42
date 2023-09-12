/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:32:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/13 01:00:33 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	mapcpy(t_map *map)
{
	char			*line;
	char			*c_line;
	t_map			c_map;

	c_map.x_max = 0;
	line = ft_substr((*map).map[c_map.x_max], 0, ft_strlen((*map).map[c_map.x_max]));
	if (!line)
		error("Cannot Copy An Empty Map\n");
	while ((*map).map[c_map.x_max])
	{
		if (c_map.x_max == 0)
			c_line = ft_substr(line, 0, ft_strlen(line));
		else
			c_line = ft_strjoin(c_line, line);
		c_line = ft_strjoin(c_line, "\n");
		free(line);
		line = ft_substr((*map).map[c_map.x_max], 0, ft_strlen((*map).map[c_map.x_max]));
		c_map.x_max++;
	}
	c_map.map = ft_split(c_line, '\n');
	c_map.cc = 0;
	c_map.ce = 0;
	c_map.cp = 0;
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
	ft_printf_fd(1, "y = %d x = %d", y, x);
	ft_printf_fd(1, " ce = %d cc = %d\n", map.ce, map.cc);
	if (map.map[x][y - 1] && map.map[x][y - 1] != '2'
		&& map.map[x][y - 1] != '1')
	{
		ft_printf_fd(1, "tchak\n");
		return (drop(map, x, y - 1));
	}
	else if (map.map[(x - 1)][y] && map.map[x - 1][y] != '2'
		&& map.map[x - 1][y] != '1')
	{
		ft_printf_fd(1, "vroum\n");
		return (drop(map, x - 1, y));
	}
	else if (map.map[x][y + 1] && map.map[x][y + 1] != '2'
		&& map.map[x][y + 1] != '1')
	{
		ft_printf_fd(1, "wiuuu\n");
		return (drop(map, x, y + 1));
	}
	else if (map.map[x + 1][y] && map.map[x + 1][y] != '2'
		&& map.map[x + 1][y] != '1')
	{
		ft_printf_fd(1, "brrr\n");
		return (drop(map, x + 1, y));
	}
	else
	{
		ft_printf_fd(1, "pouet\n");
		return (map);
	}
}

t_map	drop(t_map map, unsigned int x, unsigned int y)
{
	ft_printf_fd(1, "boum\n");
	if (map.map[x][y] == 'E')
		map.ce++;
	else if (map.map[x][y] == 'C')
		map.cc++;
	ft_printf_fd(1, "crack\n");
	map.map[x][y] = '2';
	ft_printf_fd(1, "paf\n");
	return (findaway(map, x, y));
}

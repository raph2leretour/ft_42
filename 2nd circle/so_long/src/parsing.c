/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:32:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/08 19:54:22 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	mapcpy(t_map map)
{
	t_map			c_map;
	unsigned int	x;

	x = 0;
	if (!map.map)
		clearror(map.map, "Cannot Copy An Empty Map\n");
	while (map.map[x])
	{
		c_map.map[x] = ft_substr(map.map[x], 0, ft_strlen(map.map[x]));
		x++;
	}
	c_map.x_max = map.x_max;
	c_map.y_max = map.y_max;
	c_map.cc = 0;
	c_map.ce = 0;
	c_map.cp = 0;
	return (c_map);
}

void	findstart(t_map map, unsigned int *x, unsigned int *y)
{
	while (map.map[(*x)][(*y)] == '1')
	{
		(*y)++;
		if ((*y) == map.y_max)
		{
			(*y) = 1;
			(*x)++;
		}
	}
}

int	findaway(t_map map, unsigned int *x, unsigned int *y, char c)
{
	if (map.map[(*x)][(*y) + 1] != c)
		return ((*y)++, 1);
	else if (map.map[(*x) - 1][(*y)] != c)
		return ((*x)--, 1);
	else if (map.map[(*x)][(*y) - 1] != c)
		return ((*y)--, 1);
	else if (map.map[(*x) + 1][(*y)] != c)
		return ((*x)++, 1);
	else
		return (0);
}

void	drop(t_map *map, unsigned int x, unsigned int y)
{
	if ((*map).map[x][y] == 'E')
		(*map).ce++;
	else if ((*map).map[x][y] == 'P')
		(*map).cp++;
	else if ((*map).map[x][y] == 'C')
		(*map).cc++;
	(*map).map[x][y] = 'V';
}

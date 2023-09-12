/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:32:24 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/12 15:18:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	mapcpy(t_map *map)
{
	char			*line;
	char			*c_line;
	t_map			c_map;

	c_map.x_max = 0;
	if (!(*map).map || !(*map).map[c_map.x_max])
		error("Cannot Copy An Empty Map\n");
	line = ft_substr((*map).map[c_map.x_max], 0, ft_strlen((*map).map[c_map.x_max]));
	if (!line)
		error("Cannot Copy An Empty Map\n");
	while ((*map).map[c_map.x_max])
	{
		if (c_map.x_max == 0)
			c_line = ft_substr(line, 0, ft_strlen(line));
		else
			c_line = ft_strjoin(c_line, line);
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
	if (map.map[(*x)][(*y) + 1] && map.map[(*x)][(*y) + 1] != c)
		return ((*y)++, 1);
	else if (map.map[(*x - 1)][(*y)] && map.map[(*x) - 1][(*y)] != c)
		return ((*x)--, 1);
	else if (map.map[(*x)][(*y) - 1] && map.map[(*x)][(*y) - 1] != c)
		return ((*y)--, 1);
	else if (map.map[(*x) + 1][(*y)] && map.map[(*x) + 1][(*y)] != c)
		return ((*x)++, 1);
	else
		return (0);
}

//il trouve pas .map
void	drop(t_map map, unsigned int x, unsigned int y)
{
	ft_printf_fd(1, "%d\n", x);
	ft_printf_fd(1, "%d\n", y);
	ft_printf_fd(1, "map.map%c\n", (map.map[x][y]));
	if (map.map[x][y] == 'E')
		map.ce++;
	else if (map.map[x][y] == 'P')
		map.cp++;
	else if (map.map[x][y] == 'C')
		map.cc++;
	map.map[x][y] = '1';
}

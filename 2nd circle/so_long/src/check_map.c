/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:28:06 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/07 17:03:48 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_content(t_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (map.map[x])
	{
		y = 0;
		while (map.map[x][y])
		{
			if (map.map[x][y] != '1' && map.map[x][y] != '0' &&
				map.map[x][y] != 'P' && map.map[x][y] != 'E' &&
				map.map[x][y] != 'C')
				error("Invalid Character\n");
			y++;
		}
		x++;
	}
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

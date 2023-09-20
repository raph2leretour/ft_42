/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:35:47 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/20 14:12:04 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_vars *v, t_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (map.map[x])
	{
		y = 0;
		while (map.map[x][y])
		{
			if (map.map[x][y] == '1')
				mlx_put_image_to_window(v->m, v->w, v->img.wal, y * 80, x * 80);
			else if (map.map[x][y] == '0')
				mlx_put_image_to_window(v->m, v->w, v->img.flo, y * 80, x * 80);
			else if (map.map[x][y] == 'C')
				mlx_put_image_to_window(v->m, v->w, v->img.col, y * 80, x * 80);
			else if (map.map[x][y] == 'E')
				mlx_put_image_to_window(v->m, v->w, v->img.exi, y * 80, x * 80);
			else if (map.map[x][y] == 'P')
				mlx_put_image_to_window(v->m, v->w, v->img.cha, y * 80, x * 80);
			y++;
		}
		x++;
	}
}

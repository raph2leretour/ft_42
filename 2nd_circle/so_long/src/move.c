/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:45:25 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 16:02:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vrs, t_map *map)
{
	if ((*map).map[((*vrs).height / 80) - 1][(*vrs).width / 80] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[((*vrs).height / 80) - 1][(*vrs).width / 80] != '1'
		&& (*map).map[((*vrs).height / 80) - 1][(*vrs).width / 80] != 'E')
	{
		if ((*map).map[((*vrs).height / 80) - 1][(*vrs).width / 80] == 'C')
		{
			(*map).map[((*vrs).height / 80) - 1][(*vrs).width / 80] = '0';
			(*map).cc--;
		}
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.flo, (*vrs).width, (*vrs).height);
		(*vrs).height -= 80;
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.cha, (*vrs).width, (*vrs).height);
	}
}

void	move_left(t_vars *vrs, t_map *map)
{
	if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) - 1] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) - 1] != '1'
		&& (*map).map[(*vrs).height / 80][((*vrs).width / 80) - 1] != 'E')
	{
		if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) - 1] == 'C')
		{
			(*map).map[(*vrs).height / 80][((*vrs).width / 80) - 1] = '0';
			(*map).cc--;
		}
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.flo, (*vrs).width, (*vrs).height);
		(*vrs).width -= 80;
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.cha, (*vrs).width, (*vrs).height);
	}
}

void	move_down(t_vars *vrs, t_map *map)
{
	if ((*map).map[((*vrs).height / 80) + 1][(*vrs).width / 80] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[((*vrs).height / 80) + 1][(*vrs).width / 80] != '1'
		&& (*map).map[((*vrs).height / 80) + 1][(*vrs).width / 80] != 'E')
	{
		if ((*map).map[((*vrs).height / 80) + 1][(*vrs).width / 80] == 'C')
		{
			(*map).map[((*vrs).height / 80) + 1][(*vrs).width / 80] = '0';
			(*map).cc--;
		}
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.flo, (*vrs).width, (*vrs).height);
		(*vrs).height += 80;
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.cha, (*vrs).width, (*vrs).height);
	}
}

void	move_right(t_vars *vrs, t_map *map)
{
	if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) + 1] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) + 1] != '1'
		&& (*map).map[(*vrs).height / 80][((*vrs).width / 80) + 1] != 'E')
	{
		if ((*map).map[(*vrs).height / 80][((*vrs).width / 80) + 1] == 'C')
		{
			(*map).map[(*vrs).height / 80][((*vrs).width / 80) + 1] = '0';
			(*map).cc--;
		}
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.flo, (*vrs).width, (*vrs).height);
		(*vrs).width += 80;
		mlx_put_image_to_window((*vrs).mlx, (*vrs).win, (*vrs).img.cha, (*vrs).width, (*vrs).height);
	}
}

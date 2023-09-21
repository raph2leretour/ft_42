/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:45:25 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/21 16:50:56 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *v, t_map *m)
{
	if (m->map[(v->height / 80) - 1][v->width / 80] == 'E'
		&& m->cc == 0)
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		clear(v->map.map);
		ft_clear_vars(v);
	}
	if (m->map[(v->height / 80) - 1][v->width / 80] != '1'
		&& m->map[(v->height / 80) - 1][v->width / 80] != 'E')
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		if (m->map[(v->height / 80) - 1][v->width / 80] == 'C')
		{
			m->map[(v->height / 80) - 1][v->width / 80] = '0';
			m->cc--;
		}
		mlx_put_image_to_window(v->m, v->w, v->img.flo, v->width, v->height);
		v->height -= 80;
		mlx_put_image_to_window(v->m, v->w, v->img.cha, v->width, v->height);
	}
}

void	move_left(t_vars *v, t_map *m)
{
	if (m->map[v->height / 80][(v->width / 80) - 1] == 'E'
		&& m->cc == 0)
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		clear(v->map.map);
		ft_clear_vars(v);
	}
	if (m->map[v->height / 80][(v->width / 80) - 1] != '1'
		&& m->map[v->height / 80][(v->width / 80) - 1] != 'E')
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		if (m->map[v->height / 80][(v->width / 80) - 1] == 'C')
		{
			m->map[v->height / 80][(v->width / 80) - 1] = '0';
			m->cc--;
		}
		mlx_put_image_to_window(v->m, v->w, v->img.flo, v->width, v->height);
		v->width -= 80;
		mlx_put_image_to_window(v->m, v->w, v->img.cha, v->width, v->height);
	}
}

void	move_down(t_vars *v, t_map *m)
{
	if (m->map[(v->height / 80) + 1][v->width / 80] == 'E'
		&& m->cc == 0)
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		clear(v->map.map);
		ft_clear_vars(v);
	}
	if (m->map[(v->height / 80) + 1][v->width / 80] != '1'
		&& m->map[(v->height / 80) + 1][v->width / 80] != 'E')
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		if (m->map[(v->height / 80) + 1][v->width / 80] == 'C')
		{
			m->map[(v->height / 80) + 1][v->width / 80] = '0';
			m->cc--;
		}
		mlx_put_image_to_window(v->m, v->w, v->img.flo, v->width, v->height);
		v->height += 80;
		mlx_put_image_to_window(v->m, v->w, v->img.cha, v->width, v->height);
	}
}

void	move_right(t_vars *v, t_map *m)
{
	if (m->map[v->height / 80][(v->width / 80) + 1] == 'E'
		&& m->cc == 0)
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		clear(v->map.map);
		ft_clear_vars(v);
	}
	if (m->map[v->height / 80][(v->width / 80) + 1] != '1'
		&& m->map[v->height / 80][(v->width / 80) + 1] != 'E')
	{
		v->map.mv_nb++;
		ft_printf_fd(1, "Nombre de mouvements: %d\n", v->map.mv_nb);
		if (m->map[v->height / 80][(v->width / 80) + 1] == 'C')
		{
			m->map[v->height / 80][(v->width / 80) + 1] = '0';
			m->cc--;
		}
		mlx_put_image_to_window(v->m, v->w, v->img.flo, v->width, v->height);
		v->width += 80;
		mlx_put_image_to_window(v->m, v->w, v->img.cha, v->width, v->height);
	}
}

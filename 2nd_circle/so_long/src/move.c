/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:45:25 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/17 16:36:14 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vrs, t_map *map, t_sprite sprite)
{
	if ((*map).map[(*vrs).height / 80 - 1][(*vrs).width / 80] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80 - 1][(*vrs).width / 80] != '1'
		&& (*map).map[(*vrs).height / 80 - 1][(*vrs).width / 80] != 'E')
	{
		ft_printf_fd(1, "not a wall\n");
		(*vrs).height -= 80;
		ft_printf_fd(1, "height--\n");
		if ((*map).map[(*vrs).height / 80 + 1][(*vrs).width / 80] == 'C')
		{
			(*map).map[(*vrs).height / 80 + 1][(*vrs).width / 80] = '0';
			(*map).cc--;
		}
		ft_printf_fd(1, "not a C\n");
		print_sprite((*vrs), sprite.floor, (*vrs).width, (*vrs).height + 80);
		ft_printf_fd(1, "print floor\n");
		print_sprite((*vrs), sprite.character, (*vrs).width, (*vrs).height);
		ft_printf_fd(1, "print char\n");
	}
}

void	move_left(t_vars *vrs, t_map *map, t_sprite sprite)
{
	if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 - 1] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 - 1] != '1'
		&& (*map).map[(*vrs).height / 80][(*vrs).width / 80 - 1] != 'E')
	{
		(*vrs).width -= 80;
		if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 + 1] != 'C')
		{
			(*map).map[(*vrs).height / 80][(*vrs).width / 80 + 1] = '0';
			(*map).cc--;
		}
		print_sprite((*vrs), sprite.floor, (*vrs).width + 80, (*vrs).height);
		print_sprite((*vrs), sprite.character, (*vrs).width, (*vrs).height);
	}
}

void	move_down(t_vars *vrs, t_map *map, t_sprite sprite)
{
	if ((*map).map[(*vrs).height / 80 + 1][(*vrs).width / 80] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80 + 1][(*vrs).width / 80] != '1'
		&& (*map).map[(*vrs).height / 80 + 1][(*vrs).width / 80] != 'E')
	{
		(*vrs).height += 80;
		if ((*map).map[(*vrs).height / 80 - 1][(*vrs).width / 80] != 'C')
		{
			(*map).map[(*vrs).height / 80 - 1][(*vrs).width / 80] = '0';
			(*map).cc--;
		}
		print_sprite((*vrs), sprite.floor, (*vrs).width, (*vrs).height - 80);
		print_sprite((*vrs), sprite.character, (*vrs).width, (*vrs).height);
	}
}

void	move_right(t_vars *vrs, t_map *map, t_sprite sprite)
{
	if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 + 1] == 'E'
		&& (*map).cc == 0)
	{
		clear((*vrs).m.map);
		ft_clear_vars(vrs);
	}
	if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 + 1] != '1'
		&& (*map).map[(*vrs).height / 80][(*vrs).width / 80 + 1] != 'E')
	{
		(*vrs).width += 80;
		if ((*map).map[(*vrs).height / 80][(*vrs).width / 80 - 1] != 'C')
		{
			(*map).map[(*vrs).height / 80][(*vrs).width / 80 - 1] = '0';
			(*map).cc--;
		}
		print_sprite((*vrs), sprite.floor, (*vrs).width - 80, (*vrs).height);
		print_sprite((*vrs), sprite.character, (*vrs).width, (*vrs).height);
	}
}

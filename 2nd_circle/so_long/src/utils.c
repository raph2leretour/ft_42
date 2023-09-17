/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:36:45 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/17 16:31:29 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	ft_clear_vars(vars);
	return (0);
}

int	ft_handle_key(int key, t_vars *vars)
{
	if (key == 65307)
		ft_clear_vars(vars);
	else if (key == 119 || key == 65362)
	{
		ft_printf_fd(1, "up\n");
		move_up(vars, &(*vars).m, (*vars).sprite);
	}
	else if (key == 97 || key == 65361)
	{
		ft_printf_fd(1, "left\n");
		move_left(vars, &(*vars).m, (*vars).sprite);
	}
	else if (key == 115 || key == 65364)
	{
		ft_printf_fd(1, "down\n");
		move_down(vars, &(*vars).m, (*vars).sprite);
	}
	else if (key == 100 || key == 65363)
	{
		ft_printf_fd(1, "right\n");
		move_right(vars, &(*vars).m, (*vars).sprite);
	}
	ft_printf_fd(1, "la touche enfoncee est : { %d }\n", key);
	return (0);
}

int	ft_clear_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

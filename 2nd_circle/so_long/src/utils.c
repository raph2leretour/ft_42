/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:36:45 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/19 15:25:19 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	clear(vars->map.map);
	ft_clear_vars(vars);
	return (0);
}

int	ft_handle_key(int key, t_vars *vars)
{
	if (key == 65307)
	{
		clear(vars->map.map);
		ft_clear_vars(vars);
	}
	else if (key == 119 || key == 65362)
	{
		move_up(vars, &vars->map);
	}
	else if (key == 97 || key == 65361)
	{
		move_left(vars, &vars->map);
	}
	else if (key == 115 || key == 65364)
	{
		move_down(vars, &vars->map);
	}
	else if (key == 100 || key == 65363)
	{
		move_right(vars, &vars->map);
	}
	return (0);
}

int	ft_clear_vars(t_vars *vars)
{
	mlx_destroy_image(vars->m, vars->img.cha);
	mlx_destroy_image(vars->m, vars->img.col);
	mlx_destroy_image(vars->m, vars->img.flo);
	mlx_destroy_image(vars->m, vars->img.wal);
	mlx_destroy_image(vars->m, vars->img.exi);
	mlx_destroy_window(vars->m, vars->w);
	mlx_destroy_display(vars->m);
	free(vars->m);
	exit(0);
	return (0);
}

char	*free_strjoin(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free(s1);
	return (s3);
}

void	free_image(t_image image)
{
	if (image.cha)
		free(image.cha);
	if (image.col)
		free(image.col);
	if (image.exi)
		free(image.exi);
	if (image.flo)
		free(image.flo);
	if (image.wal)
		free(image.wal);
}

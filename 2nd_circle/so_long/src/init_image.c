/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:41:37 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 15:54:37 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	init_image(t_sprite sprite, t_vars vars)
{
	t_image	image;

	image.cha = mlx_xpm_file_to_image(vars.mlx, sprite.character, &vars.width, &vars.height);
	if (!image.cha)
		error("Problem During Image Creation");
	image.col = mlx_xpm_file_to_image(vars.mlx, sprite.collectible, &vars.width, &vars.height);
	if (!image.col)
		error("Problem During Image Creation");
	image.flo = mlx_xpm_file_to_image(vars.mlx, sprite.floor, &vars.width, &vars.height);
	if (!image.flo)
		error("Problem During Image Creation");
	image.wal = mlx_xpm_file_to_image(vars.mlx, sprite.wall, &vars.width, &vars.height);
	if (!image.wal)
		error("Problem During Image Creation");
	image.exi = mlx_xpm_file_to_image(vars.mlx, sprite.exit, &vars.width, &vars.height);
	if (!image.exi)
		error("Problem During Image Creation");
	return (image);
}

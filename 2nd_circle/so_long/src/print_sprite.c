/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:46:16 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/17 16:45:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_sprite(t_vars vars, char *sprite, int x, int y)
{
	void	*image;

	image = mlx_xpm_file_to_image(vars.mlx, sprite, &vars.width, &vars.height);
	if (!image)
		error("Cannot Print Sprite\n");
	mlx_put_image_to_window(vars.mlx, vars.win, image, x, y);
}

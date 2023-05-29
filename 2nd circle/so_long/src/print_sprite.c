/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:46:16 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/23 17:38:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_sprite(t_vars vars, char *sprite, int x, int y)
{
	void	*image;

	image = mlx_xpm_file_to_image(vars.mlx, sprite, &vars.width, &vars.height);
	if (!image)
	{
		ft_printf("/!\\ Error /!\\\n--- Failed to generate image ---\n");
		exit(1);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image, x, y);
}

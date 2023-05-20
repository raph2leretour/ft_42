/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/20 16:19:30 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	void	*image;
	char	*path_image;
	t_vars	vars;

	(void) argc;
	(void) argv;
	a = 80;
	b = 80;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "zeldaaaaaaaaaaaaaaaaaaa");
	path_image = "textures/character_sprite.xpm";
	if (!path_image)
		ft_printf("karl connard\n");
	image = mlx_xpm_file_to_image(vars.mlx, path_image, &a, &b);
	if (!image)
		ft_printf("karl salope\n");
	mlx_put_image_to_window(vars.mlx, vars.win, image, 0, 0);
	mlx_key_hook(vars.win, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 1L << 17, &close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

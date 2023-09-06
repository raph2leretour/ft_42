/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/06 17:29:32 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_vars		vars;
	t_sprite	sprite;

	if (argc != 2)
	{
		ft_printf_fd(2, "Error: Bad Arguments\n");
		exit(EXIT_FAILURE);
	}
	map = read_map(argv[1]);
	check_map(map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "so_long");
	vars.height = 80;
	vars.width = 80;
	sprite = init_sprite();
	print_sprite(vars, sprite.collectible, 0, 0);
	mlx_key_hook(vars.win, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 1l << 17, &close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

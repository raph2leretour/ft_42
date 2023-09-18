/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 15:58:25 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vrs;
	t_sprite	sprite;

	if (argc != 2)
		error("Bad Arguments\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error("Invalid Path\n");
	vrs.m = read_map(open(argv[1], O_RDONLY, 0777));
	check_map(&vrs.m);
	vrs.mlx = mlx_init();
	vrs.win = mlx_new_window(vrs.mlx, vrs.m.y * 80, vrs.m.x * 80, "so_long");
	vrs.width = 80 * vrs.m.p_y;
	vrs.height = 80 * vrs.m.p_x;
	sprite = init_sprite();
	vrs.img = init_image(sprite, vrs);
	print_map(&vrs, vrs.m);
	mlx_key_hook(vrs.win, ft_handle_key, &vrs);
	mlx_hook(vrs.win, 17, 1l << 17, &close_window, &vrs);
	mlx_loop(vrs.mlx);
	clear(vrs.m.map);
	return (0);
}

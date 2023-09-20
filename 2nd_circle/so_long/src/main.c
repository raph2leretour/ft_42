/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/20 14:38:04 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_vars		vrs;
	t_sprite	sprite;

	if (argc != 2)
		error("Bad Arguments\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error("Invalid Path\n");
	fd = open(argv[1], O_RDONLY, 0777);
	if (!fd)
		error("");
	vrs.map = read_map(fd);
	close(fd);
	check_map(&vrs.map);
	vrs.m = mlx_init();
	vrs.w = mlx_new_window(vrs.m, vrs.map.y * 80, vrs.map.x * 80, "so_long");
	vrs.width = 80 * vrs.map.p_y;
	vrs.height = 80 * vrs.map.p_x;
	sprite = init_sprite();
	vrs.img = init_image(sprite, vrs);
	print_map(&vrs, vrs.map);
	mlx_key_hook(vrs.w, ft_handle_key, &vrs);
	mlx_hook(vrs.w, 17, 1l << 17, &close_window, &vrs);
	mlx_loop(vrs.m);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:41:37 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/21 16:48:52 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	init_image(t_vars v)
{
	t_image	i;

	v.s = init_sprite();
	i.cha = mlx_xpm_file_to_image(v.m, v.s.character, &v.width, &v.height);
	i.col = mlx_xpm_file_to_image(v.m, v.s.collectible, &v.width, &v.height);
	i.flo = mlx_xpm_file_to_image(v.m, v.s.floor, &v.width, &v.height);
	i.wal = mlx_xpm_file_to_image(v.m, v.s.wall, &v.width, &v.height);
	i.exi = mlx_xpm_file_to_image(v.m, v.s.exit, &v.width, &v.height);
	if (!i.exi || !i.cha || !i.col || !i.flo || !i.wal)
	{
		v.img.created = 0;
		ft_printf_fd(1, "Error: Cannot Create Images\n");
		close_window(&v);
	}
	i.created = 1;
	return (i);
}

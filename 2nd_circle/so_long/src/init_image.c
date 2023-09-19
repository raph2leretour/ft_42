/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:41:37 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/19 14:52:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	init_image(t_sprite s, t_vars v)
{
	t_image	i;

	i.cha = mlx_xpm_file_to_image(v.mlx, s.character, &v.width, &v.height);
	if (!i.cha)
		error("Problem During Image Creation");
	i.col = mlx_xpm_file_to_image(v.mlx, s.collectible, &v.width, &v.height);
	if (!i.col)
		error("Problem During Image Creation");
	i.flo = mlx_xpm_file_to_image(v.mlx, s.floor, &v.width, &v.height);
	if (!i.flo)
		error("Problem During Image Creation");
	i.wal = mlx_xpm_file_to_image(v.mlx, s.wall, &v.width, &v.height);
	if (!i.wal)
		error("Problem During Image Creation");
	i.exi = mlx_xpm_file_to_image(v.mlx, s.exit, &v.width, &v.height);
	if (!i.exi)
		error("Problem During Image Creation");
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:05:35 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/20 14:11:50 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	init_sprite(void)
{
	t_sprite	sprite;

	sprite.collectible = "textures/collectible_sprite.xpm";
	sprite.character = "textures/character_sprite.xpm";
	sprite.floor = "textures/floor_sprite.xpm";
	sprite.wall = "textures/wall_sprite.xpm";
	sprite.exit = "textures/exit_sprite.xpm";
	return (sprite);
}

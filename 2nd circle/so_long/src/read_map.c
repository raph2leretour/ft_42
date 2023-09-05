/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:09 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/05 14:22:19 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	read_map(int map_fd)
{
	char		*line;
	t_map		map;
	unsigned int	y;

	line = get_next_line(map_fd);
	map.y_max = ft_strlen(line) - 1;
	map.x_max = 0;
	while (line)
	{
		y = 0;
		while (line[y])
			y++;
}

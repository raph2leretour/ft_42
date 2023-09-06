/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:28:06 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/06 17:28:54 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// bool	check_line_content(char *line)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (line[i] && line[i] != '\n')
// 	{
// 		if (line[i] != '0' && line[i] != '1'
// 			&& line[i] != 'C' && line[i] != 'E'
// 			&& line[i] != 'P')
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

// void	check_map_shape(t_map map)
// {
// 	char			*line;
// 	unsigned int	x;
// 	unsigned int	y;
// 	unsigned int	witness_y;

// 	x = 0;
// 	witness_y = 0;
// 	line = get_next_line(map_fd);
// 	while (line)
// 	{
// 		if (x == 1)
// 			witness_y = y;
// 		y = 0;
// 		while (line[y])
// 			y++;
// 		if ((y < 3) || (x > 0 && witness_y != y)
// 			|| !check_line_content(line))
// 			return (free(line), false);
// 		free(line);
// 		line = get_next_line(map_fd);
// 		x++;
// 	}
// 	if (x < 3)
// 		return (free(line), false);
// 	return (free(line), true);
// }

// void	check_map(t_map map)
// {
// 	if (!ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4))
// 		return (true);
// 	check_map_shape(map);
// }

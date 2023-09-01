/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/01 11:37:10 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************/
/*   WRAPPER                                    */
/************************************************/
#ifndef SO_LONG_H
# define SO_LONG_H

/************************************************/
/*   INCLUDES                                   */
/************************************************/
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_vars;

typedef struct s_sprite {
	char	*collectible;
	char	*character;
	char	*floor;
	char	*wall;
	char	*exit;
}	t_sprite;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int			close_window(t_vars *vars);
int			ft_clear_vars(t_vars *vars);
int			ft_handle_key(int key, t_vars *vars);
bool		check_map(char *map_path);
bool		check_map_shape(int map_fd);
bool		check_map_content(char *line);
bool		check_map_path(char *map_path);
void		error(void);
void		print_sprite(t_vars vars, char *sprite, int x, int y);
void		print_map(t_vars vars, t_sprite sprite, char *map_path);
t_sprite	init_sprite(void);

#endif

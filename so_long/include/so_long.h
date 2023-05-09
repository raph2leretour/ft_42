/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/09 15:09:28 by rtissera         ###   ########.fr       */
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
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int		close_window(t_vars *vars);
int		ft_clear_vars(t_vars *vars);
int		ft_handle_key(int key, t_vars *vars);

#endif

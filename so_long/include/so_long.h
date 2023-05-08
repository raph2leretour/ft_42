/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/08 15:00:55 by rtissera         ###   ########.fr       */
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
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putu(unsigned int n);
int		ft_clear_vars(t_vars *vars);
int		ft_printf(const char *str, ...);
int		ft_putvoid(unsigned long int n);
int		ft_handle_key(int key, t_vars *vars);
int		ft_putnbr_base(unsigned long int n, int base);
size_t	ft_strlen(const char *s);

#endif

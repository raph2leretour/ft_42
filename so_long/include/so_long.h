/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/25 17:12:05 by rtissera         ###   ########.fr       */
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
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_list {
	char			*content;
	struct s_list	*next;
}	t_list;

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
int			ft_isdigit(int c);
int			ft_lstsize(t_list *lst);
int			close_window(t_vars *vars);
int			ft_clear_vars(t_vars *vars);
int			ft_handle_key(int key, t_vars *vars);
bool		check_map(char *map_path);
void		ft_putstr_fd(char *s, int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		print_sprite(t_vars vars, char *sprite, int x, int y);
void		print_map(t_vars vars, t_sprite sprite, char *map_path);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_sprite	init_sprite(void);
long int	ft_atoi(const char *nptr);

#endif

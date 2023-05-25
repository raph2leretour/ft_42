/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:19:29 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/25 16:58:27 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char			buf[BUFFER_SIZE + 1];
	struct s_gnl	*next;
}	t_gnl;

int		ft_lstsize(t_gnl *lst);
int		linelen(t_gnl **lst, int boool);
char	*get_next_line(int fd);
char	*put_in_line(t_gnl **lst, int i, int j);
void	*read_error(t_gnl **lst);
void	clear_old_line(t_gnl **lst);
void	ft_lstadd_back(t_gnl **lst, t_gnl *new);
t_gnl	*ft_lstnew(char *buf);
t_gnl	*ft_lstlast(t_gnl *lst);
t_gnl	*read_line(t_gnl **lst, int fd);

#endif

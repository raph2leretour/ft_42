/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:26:17 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/09 16:06:28 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

int		linelen(t_list **lst);
int		ft_lstsize(t_list *lst);
char	*get_next_line(int fd);
char	*put_in_line(t_list **lst);
void	*read_error(t_list **lst);
void	clear_old_line(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *buf);
t_list	*ft_lstlast(t_list *lst);
t_list	*read_line(t_list **lst, int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:51:15 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/02 05:05:03 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# include <unistd.h>
# include <stdlib.h>

//structure
typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

//fonctions
int		ft_lstsize(t_list *lst);
int		is_new_line(char *str);
char	*get_next_line(int fd);
char	*error_lst(t_list **bank);
char	*put_in_line(t_list **lst, int lenlin, int i);
char	*read_line(int fd, t_list **bank, int begining, int end);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *buf);
t_list	*ft_lstlast(t_list *lst);

#endif

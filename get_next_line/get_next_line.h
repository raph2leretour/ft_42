/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/24 13:30:35 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

int		is_new_line(char *str);
char	*get_next_line(int fd);
t_list	*ft_lstnew(void *buf);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);

#endif

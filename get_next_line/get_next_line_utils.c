/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:11 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/23 18:58:00 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void)
{
	t_line	*link;

	link = malloc(sizeof(t_line));
	link->next = NULL;
	return (link);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_lst = ft_lstlast(*lst);
	last_lst->next = new;
}

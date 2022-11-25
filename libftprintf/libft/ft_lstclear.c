/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:16 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/24 19:16:11 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_todel;

	while (*lst)
	{
		lst_todel = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = lst_todel;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:33:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/14 14:32:58 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*link;

	link = malloc(sizeof(t_list));
	if (!link)
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}
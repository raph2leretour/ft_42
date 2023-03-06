/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:51:38 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/06 21:05:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*quicksort(t_list *stocka)
{
	t_list	*head;
	t_list	*tmp;

	head = lst;
	tmp = ft_lstnew(lst->content);
	lst = lst->next;
	while (lst->content)
	{
		ft_lstadd_back(&tmp, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (lst = head, tmp);
}

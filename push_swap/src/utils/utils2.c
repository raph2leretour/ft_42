/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:44:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/16 15:52:19 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// t_struct	*ft_structnew(char *buf)
// {
// 	int			i;
// 	t_struct	*lst;

// 	if (!*buf)
// 		return (NULL);
// 	lst = malloc(sizeof(t_struct));
// 	if (!lst)
// 		return (NULL);
// 	i = 0;
// 	while (buf[i])
// 	{
// 		lst->buf[i] = buf[i];
// 		i++;
// 	}
// 	lst->buf[i] = '\0';
// 	lst->next = NULL;
// 	return (lst);
// }

// t_struct	*ft_structlast(t_struct *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_structadd_back(t_struct **lst, t_struct *new)
// {
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	*lst = ft_structlast(*lst);
// 	*lst->next = new;
// }

int	ft_max(t_list *lst)
{
	int		max;
	t_list	*head;

	if (!lst)
		return (INT_MIN);
	max = lst->content;
	head = lst;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (lst = head, max);
}

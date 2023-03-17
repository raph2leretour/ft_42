/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:51:38 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/16 14:15:44 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/push_swap.h"

// t_list	*ft_lstcpy(t_list *lst)
// {
// 	t_list	*head;
// 	t_list	*cpy;

// 	head = lst;
// 	cpy = ft_lstnew(lst->content);
// 	lst = lst->next;
// 	while (lst->content)
// 	{
// 		ft_lstadd_back(&cpy, ft_lstnew(lst->content));
// 		lst = lst->next;
// 	}
// 	return (lst = head, cpy);
// }

// void	lst_swap(t_list *lst, t_list *lst_next)
// {
// 	int	content;

// 	content = lst_next->content;
// 	lst_next->content = lst->content;
// 	lst->content = content;
// }

// t_list	*quicksort(t_list *stocka, int argc)
// {
// 	int		i;
// 	t_list	*head;
// 	t_list	*tmp;
// 	t_list	*tmp_next;

// 	i = 1;
// 	tmp = ft_lstcpy(stocka);
// 	head = tmp;
// 	while (i < argc - 1)
// 	{
// 		tmp_next = tmp->next;
// 		if (tmp->content > tmp_next->content)
// 		{
// 			lst_swap(tmp, tmp_next);
// 			tmp = head;
// 			i = 0;
// 		}
// 		i++;
// 	}
// 	return (tmp = head, tmp);
// }

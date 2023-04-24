/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:56 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/24 14:57:31 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	bool	test;
	t_list	*stocka;

	if (argc < 2)
		return (0);
	test = checkarg(argv);
	if (!test)
		return (ft_putstr_fd("Error\n", 1), 0);
	stocka = atoi_list(argc, argv);
	if (!stocka)
		return (ft_putstr_fd("Error\n", 1), 0);
	test = checksamearg(stocka);
	if (!test)
		return (ft_putstr_fd("Error\n", 1), 0);
	test = checksortarg(stocka);
	if (!test)
		return (0);
	convertnumb(argc, &stocka);
	push_swap(argc, stocka);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_list *stocka;

// 	(void) argc;
// 	(void) argv;
// 	stocka = ft_lstnew(2);
// 	ft_lstadd_back(&stocka, ft_lstnew(3));
// 	ft_lstadd_back(&stocka, ft_lstnew(1));
// 	rra(&stocka);
// 	lst_clean(&stocka);
// 	return (0);
// }

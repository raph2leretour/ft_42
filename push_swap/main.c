/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:56 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/11 18:01:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	int		boool;
	t_list	*stocka;
	t_list	*stockb;
	t_list	*tmp;

	if (argc < 2)
		return (0);
	boool = checkarg(argv);
	if (boool == 1)
		return (ft_putchar_fd("Error\n", 1), 0);
	stocka = atoi_list(argv);
	boool = checksamearg(stocka);
	if (boool == 1)
		return (ft_putchar_fd("Error\n", 1), 0);
	tmp = quicksort(stocka, argc);
	stockb = presort(stocka, tmp, argc);
	push_swap();
	return (0);
}

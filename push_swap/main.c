/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:56 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/02 11:02:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		boool;
	t_list	stocka;

	if (argc < 2)
		return (0);
	// Check if args are valid
	boool = checkarg(argv);
	if (boool == 1)
		return (ft_putchar_fd("Error\n", 1));
	// Convert args into stocka
	stocka = atoi_list(argv);
	// Sort stocka
	push_swap(stocka);
	return (0);
}

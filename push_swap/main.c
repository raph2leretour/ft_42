/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:56 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/01 16:29:17 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	boool;

	// Check if args are valid
	if (argc < 1)
		return (0);
	boool = checkarg(argv);
	if (boool == 1)
		return (ft_putchar_fd("Error\n", 1));
	// Convert args into stocka
	// Sort stocka
	push_swap(t_list stocka);
	return (0);
}

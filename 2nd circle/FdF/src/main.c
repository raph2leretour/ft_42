/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/05 15:37:25 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	void*	mlx_ptr;
	char*	win_ptr;

	(void) argc;
	(void) argv;
	printf("connard\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400000, 400000, "zeldaaaaaaaaaaaaaaaaaaa");
	return (0);
}

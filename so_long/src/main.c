/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:47:23 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/08 14:46:39 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argc;
	(void) argv;
	ft_printf("connard\n");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "zeldaaaaaaaaaaaaaaaaaaa");
	mlx_key_hook(vars.win, ft_handle_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

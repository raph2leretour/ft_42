/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/19 01:27:20 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6))
	{
		printf("Error: Bad Arguments\n");
		return (1);
	}
	if (init_args(ac, av, &data))
		return (1);
	if (init_forks(&data))
		return (1);
	if (init_philo(&data))
		return (1);
	if (init_threads(&data))
		return (1);
	if (join_threads(&data))
		return (1);
	destroy_fork(&data);
	clear(&data);
	return (0);
}

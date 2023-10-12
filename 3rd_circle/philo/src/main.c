/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/12 17:13:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (init_args(ac, av, &data))
			return (1);
		printf("init args\n");
		if (init_forks(&data))
			return (2);
		printf("init forks\n");
		if (init_threads(&data))
			return (3);
		printf("init threads\n");
		if (join_threads(&data))
			return (4);
		printf("join threads\n");
		destroy_fork(&data);
		printf("destroy forks\n");
	}
	return (0);
}

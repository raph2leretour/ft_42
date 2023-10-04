/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/04 15:40:29 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av, char **env)
{
	t_data		data;
	t_philo		philo;

	(void) env;
	if (ac == 5 && ac == 6)
	{
		data = init_data(av);
		if (!data)
			return (1);
		philo = init_philo(data);
		if (pthread_create(&p1, NULL, routine(philo, data), NULL) != 0)
		{
			destroy_philo(philo);
			return (2);
		}
		if (pthread_join(p1, NULL) != 0)
		{
			destroy_philo(philo);
			return (3);
		}
		destroy_fork(philo);
	}
	return (0);
}

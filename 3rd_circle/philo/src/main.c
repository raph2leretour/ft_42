/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/05 17:30:06 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int			i;
	t_data		data;
	t_philo		philo;

	if (ac == 5 && ac == 6)
	{
		data = init_data(av);
		if (!data.time_to_sleep)
			return (1);
		if (init_philo(&philo))
			return (2);
		init_threads(&philo);
		join_threads(&philo);
		destroy_fork(philo);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/05 11:24:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	init_data(char **argv)
{
	t_data	data;

	data.number_of_philosophers = atouille(argv[1]);
	if (data.nbr_of_philo < 0 || data.nbr_of_philo > 200)
		return (NULL);
	data.time_to_die = atouille(argv[2]);
	if (data.time_to_die < 0)
		return (NULL);
	data.time_to_eat = atouille(argv[3]);
	if (data.time_to_eat < 0)
		return (NULL);
	data.time_to_sleep = atouille(argv[4]);
	if (data.time_to_sleep < 0)
		return (NULL);
	if (argv[5])
	{
		data.nbr_each_philo_must_eat = atouille(argv[5]);
		if (data.nbr_each_philo_must_eat < 0)
			return (NULL);
	}
	return (data);
}

void	init_philo(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->all_forks, NULL);
	i = 1;
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_init(&data->all_forks[i], NULL);
		i++;
	}
}

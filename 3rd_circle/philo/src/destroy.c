/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:23:14 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/19 01:33:43 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].philo, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	destroy_fork(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->eat_m);
	pthread_mutex_destroy(&data->stop_m);
	pthread_mutex_destroy(&data->start_time_m);
	pthread_mutex_destroy(&data->print);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->all_forks[i]);
		pthread_mutex_destroy(&data->philo[i].meal_m);
		i++;
	}
}

void	clear(t_data *data)
{
	free(data->philo);
	free(data->all_forks);
}

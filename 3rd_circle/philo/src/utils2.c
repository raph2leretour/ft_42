/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:54:07 by raphael           #+#    #+#             */
/*   Updated: 2023/10/16 17:06:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_stop(t_data *data)
{
	int				i;
	long long int	time;

	time = get_time_in_ms();
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].time_last_meal_m);
		if (time - data->philo[i].time_last_meal >= data->time_to_die)
		{
			pthread_mutex_unlock(&data->philo[i].time_last_meal_m);
			pthread_mutex_lock(&data->stop_m);
			data->stop_v = 1;
			pthread_mutex_unlock(&data->stop_m);
			ft_print("died", &data->philo[i]);
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].time_last_meal_m);
	}
	return (0);
}

int	is_full(t_data *data)
{
	pthread_mutex_lock(&data->eat_m);
	if (data->nb_philo_eat > 0 && data->eat_v >= data->nb_philo)
	{
		pthread_mutex_unlock(&data->eat_m);
		pthread_mutex_lock(&data->stop_m);
		data->stop_v = 1;
		pthread_mutex_unlock(&data->stop_m);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_m);
	return (0);
}

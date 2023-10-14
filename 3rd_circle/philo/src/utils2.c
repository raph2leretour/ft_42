/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:54:07 by raphael           #+#    #+#             */
/*   Updated: 2023/10/14 13:54:40 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_end(t_data *data)
{
	int				i;
	long long int	time;

	pthread_mutex_lock(&data->eat_m);
	if (data->nb_philo_eat > 0 && data->eat_v >= data->nb_philo)
	{
		pthread_mutex_unlock(&data->eat_m);
		return (1);
	}
	time = get_time_in_ms();
	i = 0;
	while (i < data->nb_philo)
	{
		if (time - data->philo[i].time_last_meal >= data->time_to_die)
		{
			pthread_mutex_unlock(&data->eat_m);
			pthread_mutex_lock(&data->died_m);
			data->died_v = 1;
			pthread_mutex_unlock(&data->died_m);
			ft_print("died", data);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->eat_m);
	return (0);
}

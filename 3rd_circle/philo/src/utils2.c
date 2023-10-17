/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:54:07 by raphael           #+#    #+#             */
/*   Updated: 2023/10/17 19:20:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_died(t_data *data, long long int time, int i)
{
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->start_time_m);
	printf("%lld %d %s\n", time - data->start_time, \
		data->philo[i].id + 1, "died");
	pthread_mutex_unlock(&data->print);
	pthread_mutex_unlock(&data->start_time_m);
}

int	is_stop(t_data *data)
{
	int				i;
	long long int	time;

	i = 0;
	time = get_time_in_ms();
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].meal_m);
		if (time - data->philo[i].time_last_meal >= data->time_to_die \
			&& data->philo[i].time_last_meal != 0)
		{
			pthread_mutex_unlock(&data->philo[i].meal_m);
			pthread_mutex_lock(&data->stop_m);
			data->stop_v = 1;
			pthread_mutex_unlock(&data->stop_m);
			stop_died(data, time, i);
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].meal_m);
		i++;
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

void	take_forks(t_philo *philo)
{
	if (philo->id == 0 && philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo);
		pthread_mutex_unlock(philo->left_fork);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork);
		ft_print("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		ft_print("has taken a fork", philo);
	}
}

int	error(char *s, t_data *data)
{
	printf("Error: %s\n", s);
	if (data->all_forks)
		free(data->all_forks);
	if (data->philo)
		free(data->philo);
	join_threads(data);
	destroy_fork(data);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/16 18:02:19 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	long long int	fork_wait;

	fork_wait = get_time_in_ms();
	pthread_mutex_lock(philo->right_fork);
	ft_print("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	ft_print("has taken a fork", philo);
	ft_print("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_routine(t_philo *philo)
{
	eating(philo);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
	ft_print("is thinking", philo);
	ft_usleep(philo->data->time_to_eat + philo->data->time_to_sleep, philo->data);
}

void	*routinette(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	pthread_mutex_lock(&data->stop_m);
	while (!data->stop_v)
	{
		pthread_mutex_unlock(&data->stop_m);
		ft_usleep(1, data);
		if (is_full(data))
			return (NULL);
		if (is_stop(data))
			return (NULL);
		pthread_mutex_lock(&data->stop_m);
	}
	pthread_mutex_unlock(&data->stop_m);
	return (tmp);
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = (void *)philou;
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
	while (!philo->data->stop_v)
	{
		pthread_mutex_unlock(&philo->data->stop_m);
		philo_routine(philo);
		pthread_mutex_lock(&philo->data->stop_m);
	}
	pthread_mutex_unlock(&philo->data->stop_m);
	return (NULL);
}

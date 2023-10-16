/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/16 14:19:21 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo)
{
}

void	eating(t_philo *philo)
{
	long long int	fork_wait;

	fork_wait = get_time_in_ms();
	pthread_mutex_lock(&philo->right_fork);
	ft_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->left_fork);
	ft_print("has taken a fork", philo);
	ft_print("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	philo_routine(t_philo *philo)
{
	eating(philo);
	
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo);
	ft_print("is thinking", philo);
	ft_usleep(philo->data->time_to_eat + philo->data->time_to_sleep, philo);
}

void	*routinette(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	pthread_mutex_lock(&data->stop_m);
	while (!data->stop_m)
	{
		pthread_mutex_unlock(&data->stop_m);
		if (is_full(data))
			return (NULL);
		if (is_stop(data))
			return (NULL);
		pthread_mutex_lock(&data->stop_m);
	}
	pthread_mutex_unlock(&data->stop_m);
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = (t_philo *)philou;
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat, philo);
	while (!is_stop(philo->data))
		philo_routine(philo);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/17 13:01:53 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	throw_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
	pthread_mutex_lock(&philo->data->eat_m);
	pthread_mutex_lock(&philo->meal_m);
	philo->nb_meals++;
	if (philo->nb_meals == philo->data->nb_philo_eat)
		philo->data->eat_v++;
	philo->time_last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->eat_m);
	pthread_mutex_unlock(&philo->meal_m);
	ft_print("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
	throw_forks(philo);
}

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
	eating(philo);
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
	ft_print("is thinking", philo);
	ft_usleep(philo->data->time_to_eat + philo->data->time_to_sleep, \
		philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
		return ;
	pthread_mutex_unlock(&philo->data->stop_m);
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

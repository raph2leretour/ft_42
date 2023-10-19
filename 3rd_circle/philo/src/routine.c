/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/19 01:57:35 by raphael          ###   ########.fr       */
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
	{
		pthread_mutex_unlock(&philo->data->stop_m);
		throw_forks(philo);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_m);
	pthread_mutex_lock(&philo->meal_m);
	pthread_mutex_lock(&philo->data->eat_m);
	ft_print("is eating", philo);
	philo->nb_meals++;
	if (philo->nb_meals == philo->data->nb_philo_eat)
		philo->data->eat_v++;
	philo->time_last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_m);
	pthread_mutex_unlock(&philo->data->eat_m);
	ft_usleep(philo->data->time_to_eat, philo->data);
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
	ft_usleep((philo->data->time_to_eat > philo->data->time_to_sleep) \
		* (philo->data->time_to_eat - philo->data->time_to_sleep) + 1, \
		philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
}

void	*routinette(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	while (1)
	{
		if (is_full(data))
			return (NULL);
		if (is_stop(data))
			return (NULL);
	}
	return (tmp);
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = (void *)philou;
	// pthread_mutex_lock(&philo->data->start_time_m);
	// pthread_mutex_unlock(&philo->data->start_time_m);
	if (philo->data->nb_philo == 1)
	{
		philo_one(philo);
		return (NULL);
	}
	pthread_mutex_lock(&philo->meal_m);
	philo->time_last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_m);
	if (philo->id % 2 != 0)
		ft_usleep(10, philo->data);
	pthread_mutex_lock(&philo->data->stop_m);
	while (!philo->data->stop_v)
	{
		pthread_mutex_unlock(&philo->data->stop_m);
		philo_routine(philo);
		pthread_mutex_unlock(&philo->data->stop_m);
		pthread_mutex_lock(&philo->data->stop_m);
	}
	pthread_mutex_unlock(&philo->data->stop_m);
	return (NULL);
}

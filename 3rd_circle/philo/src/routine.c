/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/13 12:28:30 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_m);
	philo->data->stop_v = 1;
	pthread_mutex_unlock(&philo->data->stop_m);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	eating(t_philo *philo)
{
	long long int	fork_wait;

	fork_wait = get_time_in_ms();
	pthread_mutex_lock(&philo->right_fork);
	ft_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->left_fork);
	ft_print("has taken a fork", philo);
	if (is_stop(philo->data))
	{
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return ;
	}
	if (get_time_in_ms() - fork_wait > philo->data->time_to_die)
	{
		philo_die(philo);
		return ;
	}
	ft_print("is eating", philo);
	philo->nb_meals++;
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	philo_routine(t_philo *philo)
{
	if (is_stop(philo->data))
		return ;
	eating(philo);
	if (is_stop(philo->data))
		return ;
	if (philo->data->nbr_philo_eat > 0 &&philo->nb_meals >= philo->data->nbr_philo_eat)
	{
		pthread_mutex_lock(&philo->data->stop_m);
		philo->data->stop_v = 1;
		pthread_mutex_unlock(&philo->data->stop_m);
		return ;
	}
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo);
	if (is_stop(philo->data))
		return ;
	ft_print("is thinking", philo);
	ft_usleep(philo->data->time_to_eat + philo->data->time_to_sleep, philo);
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = (t_philo *)philou;
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat, philo);
	printf("stop_v = %d\n", philo->data->stop_v);
	while (!is_stop(philo->data))
	{
		printf("id = %d, nb_meals = %ld, time_last_meal = %ld\n", philo->id, philo->nb_meals, philo->time_last_meal);
		philo_routine(philo);
	}
	return (NULL);
}

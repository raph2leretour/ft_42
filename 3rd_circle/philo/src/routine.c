/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/12 15:38:13 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	ft_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->left_fork);
	ft_print("has taken a fork", philo);
	ft_print("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}

void	philo_routine(t_philo *philo)
{
	eating(philo);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo);
	ft_print("is thinking", philo);
	ft_usleep(philo->data->time_to_eat + time_to_sleep, philo);
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

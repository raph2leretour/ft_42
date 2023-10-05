/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/05 17:31:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_data data, t_philo philo)
{
	usleep(0 * 1000);
}

int	sleeping(t_data data, t_philo philo)
{
	printf("%d %d is sleeping\n", time, data.nbr_of_philo);
}

void	*eating(t_data data, t_philo philo)
{
	pthread_mtx_lock(&philo.fork);
	printf("%d %d is eating\n", time, data.nbr_of_philo);
	pthread_mtx_unlock(&philo.fork);
}

int	thinking(t_data data, t_philo philo)
{
	printf("%d %d is thinking\n", time, data.nbr_of_philo);
}

int	dying(t_data data, t_philo philo)
{
	printf("%d %d died\n", time, data.nbr_of_philo);
}

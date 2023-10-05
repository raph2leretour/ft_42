/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:23:14 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/05 17:27:40 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_of_philo)
	{
		if (pthread_join(philo->philo[i], NULL) != 0)
		{
			destroy_philo(philo);
			return (4);
		}
		i++;
	}
}

void	destroy_fork(t_philo philo)
{
	int	i;

	i = 0;
	while (i < philo.data->nbr_of_philo)
	{
		pthread_mutex_destroy(&philo.philo[i]);
		i++;
	}
}

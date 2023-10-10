/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/10 15:29:54 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philou)
{
	t_data	*data;

	data = (t_data *)philou;
	return (NULL);
}

int	sleeping(t_data data)
{
	printf("%ld %d is sleeping\n", get_time_in_ms(), data.nbr_of_philo);
	return (0);
}

int	eating(t_data data)
{
	printf("%ld %d is eating\n", get_time_in_ms(), data.nbr_of_philo);
	return (0);
}

int	thinking(t_data data)
{
	printf("%ld %d is thinking\n", get_time_in_ms(), data.nbr_of_philo);
	return (0);
}

int	dying(t_data data)
{
	printf("%ld %d died\n", get_time_in_ms(), data.nbr_of_philo);
	return (0);
}

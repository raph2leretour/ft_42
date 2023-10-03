/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:19 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/03 16:14:13 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_data data, t_mtx mtx)
{
	usleep(0 * 1000);
}

int	sleeping(t_data data, t_mtx mtx)
{
	printf("%d %d is sleeping\n", time, data.number_of_philosophers);
}

void	*eating(t_data data, t_mtx mtx)
{
	pthread_mtx_lock(&mtx.mtx);
	printf("%d %d is eating\n", time, data.number_of_philosophers);
	pthread_mtx_unlock(&mtx.mtx);
}

int	thinking(t_data data, t_mtx mtx)
{
	printf("%d %d is thinking\n", time, data.number_of_philosophers);
}

int	dying(t_data data, t_mtx mtx)
{
	printf("%d %d died\n", time, data.number_of_philosophers);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:23:14 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/04 15:40:16 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_fork(t_philo philo)
{
	while (philo)
	{
		pthread_mutex_destroy(&philo.fork);
		philo = philo->next;
	}
}

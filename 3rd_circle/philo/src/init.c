/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/09 14:16:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_of_philo)
	{
		if (pthread_create(&philo->philo[i], NULL, &routine, (void *)philo))
		{
			destroy_fork((*philo));
			return ;
		}
		i++;
	}
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->nbr_of_philo = atouille(argv[1]);
	if (data->nbr_of_philo < 0)
		return (1);
	data->time_to_die = atouille(argv[2]);
	if (data->time_to_die < 0)
		return (2);
	data->time_to_eat = atouille(argv[3]);
	if (data->time_to_eat < 0)
		return (3);
	data->time_to_sleep = atouille(argv[4]);
	if (data->time_to_sleep < 0)
		return (4);
	data->nbr_each_philo_must_eat = -1;
	if (argc == 5)
	{
		data->nbr_each_philo_must_eat = atouille(argv[5]);
		if (data->nbr_each_philo_must_eat < 0)
			return (5);
	}
	data->start_time = get_time_in_ms();
	return (0);
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_of_philo)
	{
		if (pthread_mutex_init(&philo->data->all_forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

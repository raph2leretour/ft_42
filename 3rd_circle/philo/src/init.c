/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/05 17:29:22 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_treads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_of_philo)
	{
		if (pthread_create(philo->philo[i], NULL, &routine, philo) != 0)
		{
			destroy_philo((*philo));
			return (3);
		}
		i++;
	}
}

t_data	init_data(char **argv)
{
	t_data	data;

	data.nbr_of_philo = atouille(argv[1]);
	if (data.nbr_of_philo < 0 || data.nbr_of_philo > 200)
		return ;
	data.time_to_die = atouille(argv[2]);
	if (data.time_to_die < 0)
		return ;
	data.time_to_eat = atouille(argv[3]);
	if (data.time_to_eat < 0)
		return ;
	data.time_to_sleep = atouille(argv[4]);
	if (data.time_to_sleep < 0)
		return ;
	if (argv[5])
	{
		data.nbr_each_philo_must_eat = atouille(argv[5]);
		if (data.nbr_each_philo_must_eat < 0)
			return ;
	}
	return (data);
}

int	init_philo(t_data *philo)
{
	int	i;

	pthread_mutex_init(&philo->all_forks, NULL);
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		if (pthread_mutex_init(&philo->all_forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

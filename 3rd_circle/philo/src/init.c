/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/04 15:27:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	init_data(char **argv)
{
	t_data	data;

	data.number_of_philosophers = atouille(argv[1]);
	if (data.number_of_philosophers < 1)
		return (NULL);
	data.time_to_die = atouille(argv[2]);
	if (data.time_to_die < 0)
		return (NULL);
	data.time_to_eat = atouille(argv[3]);
	if (data.time_to_eat < 0)
		return (NULL);
	data.time_to_sleep = atouille(argv[4]);
	if (data.time_to_sleep < 0)
		return (NULL);
	if (argv[5])
	{
		data.number_of_times_each_philosopher_must_eat = atouille(argv[5]);
		if (data.number_of_times_each_philosopher_must_eat < 0)
			return (NULL);
	}
	return (data);
}

t_philo	init_philo(t_data data)
{
	int		i;
	t_philo	philo;
	t_philo	head;

	pthread_mutex_init(&philo.fork, NULL);
	head = philo;
	i = 1;
	while (i < data.number_of_pilosophers)
	{
		pthread_mutex_init(&philo.fork, NULL);
		philo = philo->next;
	}
	philo->next = NULL;
	return (head);
}

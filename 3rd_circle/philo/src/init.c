/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:04 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	init_data(char **argv)
{
	t_data	data;

	data.number_of_philosophers = argv[1][0];
	data.time_to_die = argv[2][0];
	data.time_to_eat = argv[3][0];
	data.time_to_sleep = argv[4][0];
	return (data);
}

t_mtx	init_mtx(t_data data)
{
	int		i;
	t_mtx	mtx;
	t_mtx	head;

	pthread_mutex_init(&mtx.mtx, NULL);
	head = mtx;
	mtx->data = data;
	i = 1;
	while (i < data.number_of_pilosophers)
	{
		pthread_mutex_init(&mtx.mtx, NULL);
		mtx->data = data;
		mtx = mtx->next;
	}
	mtx->next = NULL;
	return (head);
}

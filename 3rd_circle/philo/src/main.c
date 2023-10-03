/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/10/03 16:08:03 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av, char **env)
{
	t_data		data;
	t_mtx		mtx;
	pthread_t	p1;

	(void) env;
	if (ac == 5)
	{
		data = init_data(av);
		mtx = init_mtx(data);
		pthread_mutex_init(&mtx.mtx, NULL);
		if (pthread_create(&p1, NULL, routine(mtx), NULL) != 0)
			return (1);
		if (pthread_join(p1, NULL) != 0)
			return (2);
		pthread_mutex_destroy(&mtx.mtx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:27:39 by raphael           #+#    #+#             */
/*   Updated: 2023/09/30 17:18:07 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int ac, char **av, char **env)
{
	pthread_t	p1;
	t_mutex		mutex;

	(void) ac;
	(void) av;
	(void) env;
	pthread_mutex_init(&mutex.mutex, NULL);
	if (pthread_create(&p1, NULL, &routine(mutex), NULL) != 0)
		return (1);
	if (pthread_join(p1, NULL) != 0)
		return (2);
	pthread_mutex_destroy(&mutex.mutex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/04 15:59:54 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************/
/*   WRAPPER                                    */
/************************************************/
#ifndef PHILO_H
# define PHILO_H

/************************************************/
/*   INCLUDES                                   */
/************************************************/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_data {
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	int		start_time;
}	t_data;

typedef struct s_philo {
	pthread_t		*philo;
	pthread_mutex_t	fork;
	t_philo			*next;
}	t_philo;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int		atouille(char *str);
int		dying(t_data data, t_philo philo);
int		thinking(t_data data, t_philo philo);
int		sleeping(t_data data, t_philo philo);
void	*eating(t_data data, t_philo philo);
void	*routine(t_data data, t_philo philo);
t_philo	init_philo(t_data data);
t_data	init_data(char **argv);

#endif

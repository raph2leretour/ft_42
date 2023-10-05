/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/05 11:37:56 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_each_philo_must_eat;
	long			start_time;
	pthread_t		philo_died_m;
	int				philo_died;
	pthread_mutex_t	all_forks[200];
	struct s_philo	*philo;

}	t_data;

typedef struct s_philo {
	pthread_t			*philo;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		nb_meals_m;
	int					nb_meals_v;
	pthread_mutex_t		time_last_meal_m;
	long				time_last_meal_v;
	struct s_data		*data;
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

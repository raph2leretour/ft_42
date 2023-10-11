/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/11 13:58:40 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/******************************************************************************/
/*   STRUCTURES                                                               */
/******************************************************************************/
typedef struct s_data {
	int				nbr_of_philo;
	int				nbr_philo_eat;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				philo_died;
	pthread_t		philo_died_m;
	pthread_mutex_t	*all_forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	start;
	pthread_mutex_t	last_meal;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo {
	int					id;
	pthread_t			*philo;
	long				nb_meals;
	long				time_last_meal;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
	struct s_data		*data;
}	t_philo;

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
int		atouille(char *str);
int		dying(t_data data);
int		eating(t_data data);
int		thinking(t_data data);
int		sleeping(t_data data);
int		init_forks(t_data *data);
int		init_args(int argc, char **argv, t_data *data);
long	get_time_in_ms(void);
void	destroy_fork(t_philo data);
void	init_threads(t_philo *data);
void	join_threads(t_philo *data);
void	*routine(void *philou);

#endif

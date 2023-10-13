/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/13 12:41:35 by rtissera         ###   ########.fr       */
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
# include <limits.h>

/******************************************************************************/
/*   STRUCTURES                                                               */
/******************************************************************************/
typedef struct s_data {
	int				nb_philo;
	int				nb_philo_eat;
	int				stop_v;
	long long int	start_time;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	pthread_mutex_t	*all_forks;
	pthread_mutex_t	stop_m;
	pthread_mutex_t	print;
	pthread_mutex_t	start;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo {
	int					id;
	long				nb_meals;
	long				time_last_meal;
	pthread_t			philo;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
	struct s_data		*data;
}	t_philo;

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
int				is_stop(t_data *data);
int				init_forks(t_data *data);
int				ft_atoi(const char *nptr);
int				init_threads(t_data *data);
int				join_threads(t_data *data);
int				init_args(int argc, char **argv, t_data *data);
void			*routine(void *philou);
void			destroy_fork(t_data *data);
void			error(char *s, t_data *data);
void			ft_print(char *s, t_philo *philo);
void			ft_usleep(long long int time, t_philo *philo);
long long int	get_time_in_ms(void);

#endif

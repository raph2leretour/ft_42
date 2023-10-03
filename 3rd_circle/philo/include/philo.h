/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:33:22 by raphael           #+#    #+#             */
/*   Updated: 2023/10/03 16:22:27 by rtissera         ###   ########.fr       */
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
	t_mtx	*mtx;
}	t_data;

typedef struct s_mtx {
	pthread_mutex_t	mtx;
	t_data			*data;
	t_mtx			*next;
}	t_mtx;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int		dying(t_data data, t_mtx mtx);
int		thinking(t_data data, t_mtx mtx);
int		sleeping(t_data data, t_mtx mtx);
void	*eating(t_data data, t_mtx mtx);
void	*routine(t_data data, t_mtx mtx);
t_mtx	init_mtx(t_data data);
t_data	init_data(char **argv);

#endif
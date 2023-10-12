/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:49 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/12 15:29:19 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int argc, char **argv, t_data *data)
{
	data->nbr_of_philo = atoi(argv[1]);
	if (data->nbr_of_philo < 0)
		return (1);
	data->time_to_die = atoi(argv[2]);
	if (data->time_to_die < 0)
		return (2);
	data->time_to_eat = atoi(argv[3]);
	if (data->time_to_eat < 0)
		return (3);
	data->time_to_sleep = atoi(argv[4]);
	if (data->time_to_sleep < 0)
		return (4);
	data->nbr_philo_eat = -1;
	if (argc == 5)
	{
		data->nbr_philo_eat = atoi(argv[5]);
		if (data->nbr_philo_eat < 0)
			return (5);
	}
	data->stop_v = 0;
	return (0);
}

void	init_rl_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		data->philo[i].left_fork = data->all_forks[i];
		if (i == data->nbr_of_philo)
			data->philo[i].right_fork = data->all_forks[0];
		else
			data->philo[i].right_fork = data->all_forks[i + 1];
		i++;
	}
}

int	init_forks(t_data *data)
{
	int	i;

	data->all_forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
	if (!data->all_forks)
		error("Cannot Malloc Forks", data);
	data->philo = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->philo)
		error("Cannot Malloc Philo", data);
	i = 0;
	while (i < data->nbr_of_philo)
	{
		if (pthread_mutex_init(&data->all_forks[i], NULL))
			error("Cannot Init Mutex", data);
		i++;
	}
	init_rl_forks(data);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals = 0;
		data->philo[i].time_last_meal = 0;
	}
	if (pthread_mutex_init(&data->print, NULL))
		error("Cannot Init Mutex", data);
	if (pthread_mutex_init(&data->start, NULL))
		error("Cannot Init Mutex", data);
	if (pthread_mutex_init(&data->stop_m, NULL))
		error("Cannot Init Mutex", data);
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_in_ms();
	while (i < data->nbr_of_philo)
	{
		if (pthread_create(&data->philo[i].philo, NULL, &routine, (void *)data->philo))
			error("Cannot Create Thread", data);
		i++;
	}
	return (0);
}

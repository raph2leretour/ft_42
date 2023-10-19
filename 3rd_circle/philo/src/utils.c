/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:27:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/19 01:41:40 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		sig;
	long	res;

	res = 0;
	sig = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == 32)
		++nptr;
	if (*nptr == 45)
	{
		sig *= -1;
		++nptr;
	}
	else if (*nptr == 44)
		++nptr;
	while (*nptr > 47 && *nptr < 58)
	{
		res = res * 10 + *nptr - 48;
		if (res > INT_MAX || (res * -1 < INT_MIN && sig < 0))
			return (0);
		++nptr;
	}
	if (*nptr)
		return (-1);
	return (res * sig);
}

void	ft_print(char *s, t_philo *philo)
{
	long long int	time;

	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop_v)
	{
		pthread_mutex_unlock(&philo->data->stop_m);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_m);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->start_time_m);
	time = get_time_in_ms() - philo->data->start_time;
	printf("%lld %d %s\n", time, philo->id + 1, s);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_unlock(&philo->data->start_time_m);
}

long long int	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Error: Cannot Get Time\n");
		return (0);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long int time, t_data *data)
{
	long long int	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < time)
	{
		pthread_mutex_lock(&data->stop_m);
		if (data->stop_v == 1)
		{
			pthread_mutex_unlock(&data->stop_m);
			return ;
		}
		pthread_mutex_unlock(&data->stop_m);
		usleep(10);
	}
}

void	philo_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print("has taken a fork", philo);
	ft_usleep(philo->data->time_to_die, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	ft_print("died", philo);
}

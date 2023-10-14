/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:27:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/13 12:44:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		res_i;
	int		sig;
	long	res_l;

	res_l = 0;
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
		res_l = res * 10 + *nptr - 48;
		++nptr;
	}
	if (res_l > INT_MAX || (res_l > INT_MIN * -1 && sig < 0))
		return (0);
	res_i = (int)res_l;
	return (res_i * sig);
}

void	ft_print(char *s, t_philo *philo)
{
	long long int	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time_in_ms() - philo->data->start_time;
	printf("%lld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
}

long long int	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Error: Cannot Get Time\n");
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long int time, t_philo *philo)
{
	long long int	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < time)
	{
		if (is_stop(philo->data))
			return ;
		pthread_mutex_unlock(&philo->data->stop_m);
		usleep(500);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:27:50 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:37 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sig;

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
		++res;
	}
	return (res * sig);
}

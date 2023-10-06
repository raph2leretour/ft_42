/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:13 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/06 17:57:46 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Error: Cannot Get Time\n");
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

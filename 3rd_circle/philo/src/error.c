/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:42:53 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/12 14:49:31 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *s, t_data *data)
{
	int	i;

	printf("Error: %s\n", s);
	if (data->all_forks)
		free(data->all_forks);
	if (data->philo)
		free(data->philo);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atouille.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:37:36 by rtissera          #+#    #+#             */
/*   Updated: 2023/10/04 14:49:09 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	atouille(char *str)
{
	int	res;

	while (str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			printf("Error: Bad Arguments\n");
			return (-1);
		}
		res = res * 10 + *str - 48;
		++str;
	}
	return (res);
}

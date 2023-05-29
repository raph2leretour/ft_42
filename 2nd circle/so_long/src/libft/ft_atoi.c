/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:56:01 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/25 17:03:58 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

long int	ft_atoi(const char *nptr)
{
	long int	res;
	long int	sig;

	res = 0;
	sig = 1;
	while (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == 32))
		nptr++;
	if (*nptr == 45)
	{
		sig *= -1;
		nptr++;
	}
	else if (*nptr == 43)
		nptr++;
	while ((*nptr >= 48) && (*nptr <= 57))
	{
		res = (res * 10) + *nptr - 48;
		nptr++;
	}
	return (res * sig);
}

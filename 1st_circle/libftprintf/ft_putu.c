/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:49 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/12 15:57:58 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int n)
{
	int				i;
	char			c;
	long long int	nb;

	i = 0;
	c = 0;
	nb = n;
	if (nb < 10)
	{
		c = nb + 48;
		i += ft_putchar(c);
	}
	if (nb >= 10)
	{
		i += ft_putu(nb / 10);
		i += ft_putu(nb % 10);
	}
	return (i);
}

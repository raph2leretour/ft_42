/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:49 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/05 14:10:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"

void	ft_putu(unsigned int n)
{
	long unsigned int	nb;
	char			c;

	nb = n;
	c = 0;
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}

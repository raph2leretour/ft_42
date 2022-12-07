/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:12:08 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/07 13:40:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putputnbr_base(int n, int c)
{
	if ((c == 'd') || (c == 'i') || (c == 'u'))
		return (ft_putnbr_base(c, 10, "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(c, 16, "012345689abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(c, 16, "012345689ABCDEF"));
}

int	ft_putnbr_base(int n, int base, char *basechar)
{
	int			i;
	long int	nb;

	i = 0;
	nb = n;
	else
	{
		if (nb < 0)
		{
			i += ft_putchar("-");
			nb = n * (-1);
		}
		if (nb < base)
		{
			i += ft_putchar(basechar[nb]);
		}
		if (nb >= base)
		{
			ft_putnbr_fd((nb / base), fd);
			ft_putnbr_fd((nb % base), fd);
		}
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:12:08 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/08 16:30:31 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putputnbr_base(long long int n, int c)
{
	if ((c == 'd') || (c == 'i'))
		return (ft_putnbr_base(n, 10, "0123456789"));
	else if (c == 'p')
		return (ft_putnbr_base(n, 16, "0123456789abcdef"));
	else if (c == 'x')
		return (ft_putnbr_base(n, 16, "012345689abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(n, 16, "012345689ABCDEF"));
}

int	ft_putnbr_base(long long int n, int base, char *basechar)
{
	int			i;

	i = 0;
	else
	{
		if (n < 0)
		{
			i += ft_putchar("-");
			n *= -1;
		}
		if (n < base)
		{
			i += ft_putchar(basechar[nb]);
		}
		if (n >= base)
		{
			ft_putnbr_base((n / base), base, *basechar);
			ft_putnbr_base((n % base), base, *basechar);
		}
	}
	return (i);
}

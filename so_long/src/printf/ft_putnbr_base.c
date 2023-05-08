/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:12:08 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/08 14:35:46 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_putvoid(unsigned long int n)
{
	int	i;

	i = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_putnbr_base(n, 'x');
	return (i);
}

int	ft_putnbr_base(unsigned long int n, int base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_base((n / 16), base);
		i += ft_putnbr_base((n % 16), base);
	}
	else if (n < 10)
		i += ft_putnbr(n);
	else
		i += ft_putchar(n - 10 + 'a' + base - 'x');
	return (i);
}

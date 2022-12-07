/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:12:08 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/06 14:39:26 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr(int n)
{
	int			i;
	long int	nb;

	i = 0;
	nb = n;
	if (nb == INT_MIN)
		i += ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			i += ft_putchar("-");
			nb = n * (-1);
		}
		if (nb < 10)
		{
			i += ft_putchar(nb + 48);
		}
		if (nb >= 10)
		{
			ft_putnbr_fd((nb / 10), fd);
			ft_putnbr_fd((nb % 10), fd);
		}
	}
}

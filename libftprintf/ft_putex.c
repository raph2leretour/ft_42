/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:07:20 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/06 13:20:30 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"

void	ft_putex(unsigned int nb, char *base)
{
	if (nb < 16)
	{
		ft_putchar(base[nb]);
	}
	if (nb >= 16)
	{
		ft_putex((nb / 16), b);
		ft_putex((nb % 16), b);
	}
}

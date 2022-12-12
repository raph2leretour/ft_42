/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:03:07 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/12 16:31:46 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition(int c, int j, va_list arg)
{
	if (c == 'c')
		j += ft_putchar(va_arg(arg, unsigned int));
	else if (c == 'u')
		j += (ft_putu(va_arg(arg, int)));
	else if (c == 's')
		j += ft_putstr(va_arg(arg, char *));
	else if ((c == 'd') || (c == 'i'))
		j += ft_putnbr(va_arg(arg, int));
	else if (c == 'x')
		j += ft_putnbr_base(va_arg(arg, unsigned int), 'x');
	else if (c == 'X')
		j += ft_putnbr_base(va_arg(arg, unsigned int), 'X');
	else if (c == 'p')
		j += ft_putvoid(va_arg(arg, unsigned long int));
	else
		j += ft_putchar(c);
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		k;
	va_list	arg;

	i = 0;
	j = 0;
	k = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				j += ft_putchar('%');
			else
				j = condition(str[i + 1], j, arg);
			k += 2;
			i += 2;
		}
		else
			i += ft_putchar(str[i]);
	}
	va_end(arg);
	return (j + i - k);
}

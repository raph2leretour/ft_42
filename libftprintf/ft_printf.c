/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:03:07 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/06 15:20:25 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	arg;

	i = 0;
	j = 0;
	va_start(str, arg);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				j += ft_putchar(va_arg(char));
			else if (str[i + 1] == 's')
				j += ft_putstr(va_arg(char *));
			else if (str[i + 1] == 'p')
				j += ft_putv(va_arg(void *));
			else if ((str[i + 1] == 'd') || (str[i] == 'i'))
				j += ft_putnbr(va_arg(int));
			else if (str[i + 1] == 'u')
				j += ft_putu(va_arg(int));
			else if (str[i + 1] == 'x')
				j += ft_putex(va_arg(unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				j += ft_putex(va_arg(unsigned int), "0123456789ABCDEF");
			else if (str[i + 1] == '%')
				j += ft_putchar('%');
			j -= 2;
			i += 2;
		}
		else
			i += ft_putchar(str[i]);
	}
	return (j + i);
}

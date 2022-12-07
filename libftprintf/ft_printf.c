/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:03:07 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/07 14:21:39 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"

int	condition(int c, int arg, int j)
{
	if (c == 'c')
		j += ft_putchar(arg);
	else if (c == 's')
		j += ft_putstr(arg);
	else if (c == 'p')
		j += ft_putv(arg);
	else if (c == 'u')
		j += (ft_putu(arg));
	else if ((c == 'd') || (c == 'i')
		|| (c == 'x') || (c == 'X'))
		j += ft_putputnbr_base(arg, c);
	else if (c == '%')
		j += ft_putchar('%');
	return (j);
}

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
			if (str[i + 1] == '%')
				j += ft_putchar('%');
			else
				j += condition(str[i + 1], va_arg(), j);
			j -= 2;
			i += 2;
		}
		else
			i += ft_putchar(str[i]);
	}
	return (j + i);
}

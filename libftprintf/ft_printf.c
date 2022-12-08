/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:03:07 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/08 16:46:08 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	condition(int c, va_list arg, int j)
{
	if (c == 'c')
		j += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		j += ft_putstr(va_arg(arg, char *));
	else if (c == 'u')
		j += (ft_putu(va_arg(arg, int)));
	else if ((c == 'd') || (c == 'i')
		|| (c == 'p')
		|| (c == 'x') || (c == 'X'))
		j += ft_putputnbr_base(va_arg(arg, long long int), c);
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
				j += condition(str[i + 1], &va_arg(), j);
			j -= 2;
			i += 2;
		}
		else
			i += ft_putchar(str[i]);
	}
	return (j + i);
}

#include <stdio.h>
int	main()
{
	char	c = 'a';
	char	*s = "test123";
	void	*p = "39485793403958";
	int	d = INT_MIN;
	int	i = 34875;
	unsigned int	u = 982345;
	int	x = 2934;

	printf("fcontion de base:\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%", c, s, p, d, i, u, x, x);
	ft_printf("ma fcontion:\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%", c, s, p, d, i, u, x, x);
	return (0);
}

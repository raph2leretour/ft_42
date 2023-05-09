/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:05:08 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/12 16:14:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putu(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_putvoid(unsigned long int n);
int		ft_putnbr_base(unsigned long int n, int base);
size_t	ft_strlen(const char *s);

#endif

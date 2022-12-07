/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:05:08 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/07 14:27:09 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_puchar(char c);
int	ft_putstr(char *s);
int	ft_putu(unsigned int n)
int	ft_printvoid(const void s);
int	ft_printf(const char *str, ...);
int	ft_putputnbr_base(int n, int c);
int	ft_putex(unsigned int nb, char *base);

#endif

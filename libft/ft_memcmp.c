/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:50 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/21 12:05:23 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		*s1;
	int		*s2;

	i = 0;
	s1 = (int *)str1;
	s2 = (int *)str2;
	if ((!n) || (s1[i] == s2[i]))
		return (0);
	while ((s1[i] == s2[i]) && (i < n))
		i++;
	return (s1[i] - s2[i]);
}

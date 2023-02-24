/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:29 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/18 14:05:44 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c2;

	i = ft_strlen(s);
	c2 = (char)c;
	while ((i != 0) && (c2 != s[i]))
		i--;
	if (s[i] == c2)
		return ((char *)s + i);
	return (NULL);
}

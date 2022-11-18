/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:27:18 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/17 18:39:58 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strstart(const char *s1, const char *set, size_t i, size_t j)
{
	if (set[j] == s1[i])
		ft_strstart(s1, set, i + 1, 0);
	else if (set[j] != '\0')
		ft_strstart(s1, set, i, j + 1);
	return (i);
}

size_t	ft_strend(const char *s1, const char *set, size_t i, size_t j)
{
	if (set[j] == s1[i])
		ft_strend(s1, set, i - 1, 0);
	else if (set[j] != '\0')
		ft_strend(s1, set, i, j + 1);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	len;
	size_t	strstart;
	size_t	strend;

	i = 0;
	strstart = ft_strstart(s1, set, 0, 0);
	len = ft_strlen(s1);
	strend = ft_strend(s1, set, len, 0);
	len = (ft_strlen(s1) - strstart - strend);
	s2 = malloc(sizeof(char) * len);
	while (i <= len)
	{
		s2[i] = s1[strstart + i];
		i++;
	}
	return (s2);
}

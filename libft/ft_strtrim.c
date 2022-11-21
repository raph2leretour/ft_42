/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:27:18 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/21 16:37:49 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] != s1[i])
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (ft_strlen(s1));
}

size_t	getend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		j = 0;
		while (set[j] != s1[i])
			j++;
		if (set[j] == '\0')
			return (ft_strlen(s1) - i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = 0;
	start = getstart(s1, set);
	end = getend(s1, set);
	len = ft_strlen(s1) - (start + end);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while ((i + start) < len)
	{
		str[i] = s1[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:21 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/22 15:29:24 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freeerror(char **s, int i)
{
	while (i)
	{
		free(s[i]);
		i--;
	}
}

int	nbstr(const char *s, char c)
{
	long int	i;
	long int	j;

	i = 0;
	j = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
		{
			j++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

int	getnextstr(const char *s, char c, int i)
{
	long int	j;

	j = 0;
	while (s[i] && (s[i] != c))
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	long int	i;
	long int	j;
	long int	nextstr;
	char		**s2;

	i = 0;
	j = -1;
	s2 = malloc(sizeof(char *) * (nbstr(s, c) + 1));
	if (!s2)
		return (0);
	while (j++ < (nbstr(s, c)))
	{
		while (s[i] == c)
			i++;
		nextstr = getnextstr(s, c, i);
		s2[j] = ft_substr(s, i, nextstr);
		if (!s2)
		{
			freeerror(s2, j);
			return (0);
		}
		i += nextstr;
	}
	s2[j - 1] = '\0';
	return (s2);
}

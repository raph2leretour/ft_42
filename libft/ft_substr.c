/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:37:37 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/17 19:07:11 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while ((s[i]) && (i != start))
		i++;
	if (s[i] == '\0')
		return (NULL);
	while ((s[i + j]) && (j <= len))
	{
		str[j] = s[i + j];
		j++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:18 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/26 12:14:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((nmemb > sizeof(char) * INT_MAX)
		|| (size > sizeof(char) * INT_MAX)
		|| ((nmemb * size) > sizeof(char) * INT_MAX))
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	while (i < (nmemb * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

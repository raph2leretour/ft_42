/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:34:53 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/18 14:30:41 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while ((big[i]) && (i <= len))
	{
		j = 0;
		while ((little[j] == big[i + j]) && (i + j <= len))
		{
			if (little[j] == '\0')
			return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:18 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/26 14:59:20 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	test;
	char	*str;

	i = 0;
	test = nmemb * size;
	if ((test / nmemb) != size)
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

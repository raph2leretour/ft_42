/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:18 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/17 19:36:40 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc((sizeof(size)) * (nmemb));
	if ((nmemb == 0) || (size == 0) || (!str))
		return (NULL);
	ft_memset(str, 0, nmemb);
	return (str);
}

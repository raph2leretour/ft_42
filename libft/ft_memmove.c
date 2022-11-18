/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:13:27 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/17 18:13:38 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	bank;

	i = 0;
	while ((i <= ((int)n)) && (((char *)src)[i]))
	{
		bank = ((char *)src)[i];
		((char *)dest)[i] = bank;
		i++;
	}
	return (dest);
}

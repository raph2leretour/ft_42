/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/17 16:32:50 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int	fd)
{
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	char		line[2048];
	void		*buff;

	if (!fd || (BUFFER_SIZE <= 0))
		return (NULL);
}

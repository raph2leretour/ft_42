/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:54:13 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/17 13:07:42 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	if (!str)
		perror("Error");
	else
		ft_printf_fd(2, "Error: %s", str);
	exit(EXIT_FAILURE);
}

void	clear(char **tab)
{
	unsigned int	i;

	i = 0;
	if (!tab || !tab[i])
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clearror(char **tab, char *str)
{
	clear(tab);
	error(str);
}

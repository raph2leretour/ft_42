/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:50:46 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/01 15:45:26 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//free bank
int	error_lst(t_list *bank)
{
}

int	is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*put_in_line(t_list *lst, int lenlin, int decalage)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * (lenlin + 1));
	i = 0;
	while (lst->buf[i])
	{
	}
}

char	*read_line(int fd, t_list *bank)
{
	int		i;
	int		j;
	int		k;
	char	*buf[BUFFER_SIZE + 1];

	i = 0;
	if (bank->buf[0] != '\0')
	{
		while (bank->buf[i] != '\n')
			i++;
		i++;
	}
	while (is_new_line(ft_lstlast(bank)->buf) == -1)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == -1)
			return (error_lst(bank));
		else if (j == 0)
			break ;
		ft_lstadd_back(&bank, ft_lstnew(buf));
	}
	k += (ft_lstsize(bank) - 1) * BUFFER_SIZE;
	return (put_in_line(bank, (k - (BUFFER_SIZE - i)), i));
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*bank;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = read_line(fd, bank);
	if (!line)
		return (NULL);
	return (line);
}

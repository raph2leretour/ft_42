/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:50:46 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/02 18:01:16 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*error_lst(t_list **bank)
{
	t_list	*lst_next;
	t_list	*lst_current;

	lst_current = *bank;
	while (lst_current)
	{
		lst_next = lst_current->next;
		free(lst_current);
		lst_current = lst_next;
	}
	return (NULL);
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

char	*put_in_line(t_list **lst, int lenlin, int decalage)
{
	int		i;
	int		j;
	char	*line;
	t_list	*lst_next;

	line = malloc(sizeof(char) * (lenlin + 1));
	i = decalage;
	j = 0;
	while ( *lst && (*lst)->buf[0])
	{
		lst_next = (*lst)->next;
		while ((*lst)->buf[i])
		{
			line[j] = (*lst)->buf[i];
			if ((*lst)->buf[i] == '\n')
			{
				line[j + 1] = '\0';
				return (line);
			}
			i++;
			j++;
		}
		if ((*lst)->next)
			free(*lst);
		*lst = lst_next;
		i = 0;
	}
	return (line);
}

char	*read_line(int fd, t_list **bank, int start)
{
	int		bytes;
	int		lenlin;
	char	buf[BUFFER_SIZE + 1];

	buf[0] = '\0';
	if (start == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (error_lst(bank));
		else if (bytes == 0)
			return (NULL);
		ft_lstadd_back(bank, ft_lstnew(buf));
		while (is_new_line(ft_lstlast(*bank)->buf) == -1)
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes == -1)
				return (error_lst(bank));
			else if (bytes == 0)
				break ;
			ft_lstadd_back(bank, ft_lstnew(buf));
		}
	}
	lenlin = (ft_lstsize(*bank) * BUFFER_SIZE);
	return (put_in_line(bank, lenlin, start));
}

char	*get_next_line(int fd)
{
	int				start;
	char			*line;
	static t_list	*bank = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	start = 0;
	if (bank)
	{
		while (bank->buf[start] && bank->buf[start - 1] != '\n')
			start++;
	}
	line = read_line(fd, &bank, start);
	bank = del_old_line(bank, start);
	if (!line)
		return (NULL);
	return (line);
}

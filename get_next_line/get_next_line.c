/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/01/24 17:05:49 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *str)
{
	int	i;

	i = -1;
	while (str[i++])
		if (str[i] == '\n')
			return (i);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	void		buf[BUFFER_SIZE + 1];
	const char	*line;
	t_list		**lst;

	if (!fd || (BUFFER_SIZE <= 0))
		return (NULL);
	while (is_new_line(lst->buf) == 0)
	{
		read(fd, buf, BUFFER_SIZE);
		ft_lstadd_back(lst, ft_lstnew(buf));
	}
	i = is_new_line(lst->buf);
	i += (ft_lstsize(lst) - 1) * BUFFER_SIZE;
	j = 0;
	while (j++ < ft_lstsize(lst))
	{
		buf = lst->buf;
		lst = lst->next;
		line = ft_strjoin(buf, lst->buf);
		lst = lst->next;
	}
	return (line);
}

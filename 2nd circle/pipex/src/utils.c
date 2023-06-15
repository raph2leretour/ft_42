/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:42 by rtissera          #+#    #+#             */
/*   Updated: 2023/06/15 04:30:38 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	iwanttofree(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

char	*get_env(char **env)
{
	int		i;
	char	*penv;

	i = 0;
	penv = env[i];
	while (ft_strnstr(penv, "PATH=", 5) == 0)
	{
		penv = *env[i];
		i++;
	}
}

char	*get_path(char **s_cmd, char **env)
{
	char	*penv;
	char	*path;
	char	*exec;
	char	**paths;

	penv = NULL;
	while (ft_strnstr(penv, "PATH=", 5) == 0)
	{
		penv = *env;
		env++;
	}
	paths = ft_split(penv + 5, ':');
	while (*paths)
	{
		path = ft_strjoin(*paths, '/');
		exec = ft_strjoin(*paths, s_cmd[0]);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(s_cmd);
			return (exec);
		}
		free(exec);
	}
	iwanttofree(paths);
}

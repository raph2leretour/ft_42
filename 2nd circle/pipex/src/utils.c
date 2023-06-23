/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:42 by rtissera          #+#    #+#             */
/*   Updated: 2023/06/23 18:22:52 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execificator(char *cmd, char **env)
{
	char	*path;
	char	**splitcmd;

	splitcmd = ft_split(cmd, ' ');
	path = get_path(splitcmd, env);
	if (!path)
		path = cmd;
	if (execve(path, splitcmd, env) == -1)
	{
		iwanttobreakfree(splitcmd);
		error();
	}
}

void	iwanttobreakfree(char **tofree)
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

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*get_path(char **splitcmd, char **env)
{
	char	*penv;
	char	*path;
	char	*execpath;
	char	**paths;

	penv = get_env(env);
	if (!penv)
		return (ft_printf("Error: command not found"), NULL);
	paths = ft_split(penv + 5, ':');
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		execpath = ft_strjoin(*paths, splitcmd[0]);
		free(path);
		if (access(execpath, F_OK | X_OK) == 0)
		{
			free(splitcmd);
			return (execpath);
		}
		free(execpath);
	}
	iwanttobreakfree(paths);
	return (NULL);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

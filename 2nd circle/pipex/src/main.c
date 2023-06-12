/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:57:53 by rtissera          #+#    #+#             */
/*   Updated: 2023/06/12 15:54:27 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execificator(char *cmd, char **env)
{
	char	*path;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(cmd, env);
}

void	child_process(int f1, int end[2], char **av, char **env)
{
	dup2(f1, 0);
	dup2(end[1], 1);
	close(end[0]);
	execificator(av[2], env);
}

void	parent_process(int f2, int end[2], char **av, char **env)
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(f2, 1);
	dup2(end[0], 0);
	close(end[1]);
	execificator(av[2], env);
}

void	pipex(int f1, int f2, char **av, char **env)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork"));
	if (!parent)
		child_process(f1, end, av, env);
	else
		parent_process(f2, end, av, env);
}

int	main(int ac, char **av, char **env)
{
	int	f1;
	int	f2;

	if (ac != 5)
		return (ft_printf("Wrong argument count\n"), -1);
	f1 = open(av[1], O_RDONLY, 0777);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	pipex(f1, f2, av, env);
	close(f1);
	close(f2);
	return (0);
}

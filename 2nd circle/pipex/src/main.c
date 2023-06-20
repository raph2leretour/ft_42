/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:57:53 by rtissera          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:33 by rtissera         ###   ########.fr       */
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
		ft_printf("Error: command not found");
		exit (0);
	}
}

void	child_process(int f1, int end[2], char **av, char **env)
{
	ft_printf("f1: %d\nend[2]: %d\n", f1, end[1]);
	dup2(f1, 0);
	ft_printf("f1: %d\nend[2]: %d\n", f1, end[1]);
	dup2(end[1], 1);
	ft_printf("f1: %d\nend[2]: %d\n", f1, end[1]);
	close(end[0]);
	execificator(av[2], env);
}

void	parent_process(int f2, int end[2], char **av, char **env)
{
	int	status;

	ft_printf("f2: %d\nend[2]: %d\n", f2, end[0]);
	waitpid(-1, &status, 0);
	ft_printf("waitpid check");
	dup2(f2, 1);
	dup2(end[0], 0);
	close(end[1]);
	execificator(av[3], env);
}

void	pipex(int f1, int f2, char **av, char **env)
{
	int		end[2];
	pid_t	parent;

	if (pipe(end) == -1)
		exit (-1);
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
	if (f1 == -1)
	{
		perror("Error");
		exit(-1);
	}
	f2 = open(av[4],O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (f2 == -1)
	{
		perror("Error");
		close(f1);
		exit(-1);
	}
	pipex(f1, f2, av, env);
	close(f1);
	close(f2);
	return (0);
}

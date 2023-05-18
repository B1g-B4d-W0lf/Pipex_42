/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:51:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/17 04:10:57 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**findpath(char **envp)
{
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

void	parse(int argc, char **argv, char **envp, t_pipex *pix)
{
	if (argc < 5)
	{
		perror("Not enough args");
		exit(EXIT_FAILURE);
	}
	pix->fd[0] = open(argv[1], O_RDONLY);
	if (access(argv[1], R_OK) == -1)
		perror("You can't read me");
	pix->fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (access(argv[1], W_OK) == -1)
		perror("You can't write me");
	if (pix->fd[0] < 0 || pix->fd[1] < 0)
		perror("Missing a file are we?");
	pix->cmd1 = ft_split(argv[2], ' ');
	pix->cmd2 = ft_split(argv[3], ' ');
	pix->paths = findpath(envp);
}

void	pipex(t_pipex pix, char **argv)
{
	pid_t	pid[2];
	int		link[2];

	pipe(link);
	pid[0] = fork();
	if (pid[0] == 0)
		firstchild(pix, argv, link);
	close(link[1]);
	close(pix.fd[0]);
	pid[1] = fork();
	if (pid[1] == 0)
		secondchild(pix, argv, link);
	close(link[0]);
	close(pix.fd[1]);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
	freetab(pix.paths);
	freetab(pix.cmd1);
	freetab(pix.cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pix;

	parse(argc, argv, envp, &pix);
	pipex(pix, argv);
	return (0);
}

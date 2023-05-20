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

void	parse(int argc, char **argv, char **envp, t_pipex *pix)
{
	if (argc < 5)
	{
		perror("Not enough args");
		exit(EXIT_FAILURE);
	}
	pix->fd[0] = open(argv[1], O_RDONLY);
	if (access(argv[1], R_OK) == -1)
	{
		perror("file1: Permission denied");
		exit(0);
	}
	pix->fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (access(argv[4], W_OK) == -1)
	{
		perror("file2: Permission denied");
		exit(0);
	}
	if (pix->fd[0] < 0 || pix->fd[1] < 0)
		perror("No such file or directory");
	cmdges(argv, pix);
	pix->paths = findpath(envp);
}

void	pipex(t_pipex *pix, char **envp)
{
	pid_t	pid[2];
	int		link[2];

	pipe(link);
	pid[0] = fork();
	if (pid[0] == 0)
		firstchild(pix, link, envp);
	close(link[1]);
	close((pix->fd)[0]);
	pid[1] = fork();
	if (pid[1] == 0)
		secondchild(pix, link, envp);
	close(link[0]);
	close((pix->fd)[1]);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
	destroy(pix->paths, pix->cmd1, pix->cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pix;

	pix.paths = 0;
	pix.cmd1 = 0;
	pix.cmd2 = 0;
	parse(argc, argv, envp, &pix);
	pipex(&pix, envp);
	return (0);
}

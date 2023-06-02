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
	if (argc < 5 || argc > 5)
	{
		perror("Wrong arg number");
		exit(EXIT_FAILURE);
	}
	pix->fd[0] = open(argv[1], O_RDONLY);
	pix->fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (pix->fd[0] < 0)
		perror("file 1");
	if (pix->fd[1] < 0)
		perror("file 2");
	cmdges(argv, pix, argc);
	pix->paths = findpath(envp);
		pix->link = createpipe(pix);
	pix->pid = malloc(pix->cmdsize * sizeof(int));
	if (!pix->pid)
		return ;
	openpipe(&pix->link, pix);
}

void	waiting(t_pipex *pix, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		waitpid(pix->pid[i], 0, 0);
		i++;
	}
	free(pix->pid);
	destroy(pix->paths, pix);
}

void	pipex(t_pipex *pix, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	pix->pid[i] = fork();
	if (pix->pid[i] == 0)
		firstchild(pix, pix->link[j], envp);
	if (pix->fd[0] >= 0)
		close(pix->fd[0]);
	pix->pid[i] = fork();
	if (pix->pid[i] == 0)
		secondchild(pix, pix->link[j], envp);
	closepipe(pix->link, pix);
	if (pix->fd[1] >= 0)
		close(pix->fd[1]);
	waiting(pix, j);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pix;

	pix.paths = 0;
	pix.cmd = 0;
	pix.link = 0;
	pix.cmdsize = argc - 3;
	pix.envp = envp;
	parse(argc, argv, envp, &pix);
	pipex(&pix, envp);
	return (0);
}

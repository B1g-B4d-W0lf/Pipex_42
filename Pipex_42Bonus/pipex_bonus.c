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

#include "pipex_bonus.h"

void	parse(int argc, char **argv, char **envp, t_pipex *pix)
{
	if (argc < 5)
	{
		perror("Not enough args");
		exit(EXIT_FAILURE);
	}
	pix->fd[0] = open(argv[1], O_RDONLY);
	pix->fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (access(argv[1], R_OK) == -1)
	{
		perror("file1: Permission denied");
		exit(0);
	}
	if (access(argv[4], W_OK) == -1)
	{
		perror("file2: Permission denied");
		exit(0);
	}
	if (pix->fd[0] < 0 || pix->fd[1] < 0)
		perror("No such file or directory");
	cmdges(argv, pix, argc);
	pix->paths = findpath(envp);
}

int	**createpipe(t_pipex *pix)
{
	int	i;
	int	j;
	int	**link;

	i = 0;
	j = 0;
	while(pix->cmd[i])
		i++;
	pix->cmdsize = i;
	link = malloc(pix->cmdsize * sizeof(int *));
	if (!link)
		return(NULL);
	while (j < i)
	{
		link[j] = malloc(2 * sizeof(int));
		if (!link[j])
			return(NULL);
		j++;
	}
	return (link);	
}

void	closepipe(int **link, t_pipex *pix)
{
	int	i;

	i = 0;
	while (i < pix->cmdsize)
	{
		close(link[i][0]);
		close(link[i][1]);
		free(link[i]);
		i++;
	}
	free(link);
}

void	openpipe(int ***link, t_pipex *pix)
{
	int	i;

	i = 0;
	while (i < pix->cmdsize)
	{
		pipe((*link)[i]);
		i++;
	}
}

void	pipex(t_pipex *pix, char **envp)
{
	pid_t	*pid;
	int		**link;
	int		i;

	i = 0;

	link = createpipe(pix);
	pid = malloc(pix->cmdsize * sizeof(int));
	if (!pid)
		return;
	openpipe(&link, pix);
	pid[i] = fork();
	if (pid[i] == 0)
		firstchild(pix, link[i], envp);
	// j  = 0
	// while (j < argc - 5, ou nb cmd - 2 )
	//{
	//	all middle child (pix, link[i], link[j + 1], envp)
	//
	//	j++;
	//}

	// second child
	waitpid(pid[i], 0, 0);
	free(pid);
	closepipe(link, pix);
	destroy(pix->paths, pix);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pix;

	pix.paths = 0;
	pix.cmd = 0;
	parse(argc, argv, envp, &pix);
	pipex(&pix, envp);
	return (0);
}

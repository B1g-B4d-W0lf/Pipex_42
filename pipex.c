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

void	cmdges(char **argv, t_pipex *pix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[2][i] == ' ' || (argv[2][i] >= 9 && argv[2][i] <= 13))
		i++;
	while (argv[3][j] == ' ' || (argv[3][j] >= 9 && argv[3][j] <= 13))
		j++;
	if (argv[2][i] != '\0')
		pix->cmd1 = ft_split(argv[2], ' ');
	else
		perror("cmd1 is empty");
	if (argv[3][j] != '\0')
		pix->cmd2 = ft_split(argv[3], ' ');
	else
		perror("cmd2 is empty");
	if (argv[2][i] == '\0' && argv[3][j] == '\0')
	{
		close(pix->fd[0]);
		close(pix->fd[1]);
		perror("no cmds");
		exit(0);
	}
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
	{
		perror("You can't read me");
		exit(0);
	}
	pix->fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (access(argv[4], W_OK) == -1)
	{
		perror("You can't write me");
		exit(0);
	}
	if (pix->fd[0] < 0 || pix->fd[1] < 0)
		perror("Missing a file are we?");
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

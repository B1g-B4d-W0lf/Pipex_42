/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:53:40 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/20 20:54:16 by wfreulon         ###   ########.fr       */
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

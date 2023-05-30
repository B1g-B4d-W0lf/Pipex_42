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

#include "pipex_bonus.h"

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
	int	k;
	int	l;

	i = 0;
	j = 2;
	k = 2;
	l = 0;
	while (j < argc)
	{
		while (argv[j][i] == ' ' || (argv[j][i] >= 9 && argv[j][i] <= 13))
			i++;
		if (argv[j][i] != '\0')
		{
			pix->cmd[l] = ft_split(argv[j], ' ');
			l++;
		}
		else
		{
			perror("cmd is empty");	
			k++;
		}
		j++;
		i = 0;
	}
	if (j == k)
	{
		close(pix->fd[0]);
		close(pix->fd[1]);
		perror("no cmds");
		exit(0);
	}
	else
		pix->cmd[j] = '\0';
}

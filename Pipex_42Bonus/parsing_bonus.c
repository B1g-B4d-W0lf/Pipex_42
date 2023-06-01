/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:53:40 by wfreulon          #+#    #+#             */
/*   Updated: 2023/06/01 20:42:33 by wfreulon         ###   ########.fr       */
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

void	errorcmd(t_pipex *pix)
{
	close(pix->fd[0]);
	close(pix->fd[1]);
	free(pix->cmd);
	perror("no cmds");
	exit(0);
}

void	cmdges(char **argv, t_pipex *pix, int argc)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 2;
	k = 2;
	l = 0;
	pix->cmd = malloc((argc - 2) * sizeof(char **));
	if (!pix->cmd)
		return ;
	while (j < argc - 1)
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
			pix->cmd[l] = NULL;
			l++;
			k++;
		}
		j++;
		i = 0;
	}
	if (j == k)
		errorcmd(pix);
	else
		pix->cmd[(argc - 3)] = '\0';
}

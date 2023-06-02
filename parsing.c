/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:53:40 by wfreulon          #+#    #+#             */
/*   Updated: 2023/06/02 03:58:10 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**findpath(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp && envp[i])
	{
		while (ft_strncmp("PATH", envp[i], 4))
			i++;
		paths = ft_split(envp[i] + 5, ':');
		return (paths);
	}
	return (NULL);
}

void	cmdges(char **argv, t_pipex *pix, int argc)
{
	int	tab[4];

	tab[1] = 2;
	tab[2] = 2;
	tab[3] = 0;
	pix->cmd = malloc((argc - 2) * sizeof(char **));
	if (!pix->cmd)
		return ;
	while (tab[1] < argc - 1)
	{	
		tab[0] = 0;
		while (argv[tab[1]][tab[0]] == ' ' || (argv[tab[1]][tab[0]] >= 9
			&& argv[tab[1]][tab[0]] <= 13))
			tab[0]++;
		if (argv[tab[1]][tab[0]] != '\0')
			pix->cmd[tab[3]] = ft_split(argv[tab[1]], ' ');
		else
		{
			pix->cmd[tab[3]] = NULL;
			tab[2]++;
		}
		tab[3]++;
		tab[1]++;
	}
	pix->cmd[(argc - 3)] = '\0';
}

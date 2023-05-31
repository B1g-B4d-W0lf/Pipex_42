/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:28:46 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/17 04:03:59 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execcmd(t_pipex *pix, char **envp, char **cmd)
{
	int	i;

	i = 0;
	if (cmd_check(cmd) == 1)
	{
		while ((pix->paths)[i])
		{
			(pix->paths)[i] = ft_sup_join((pix->paths)[i], '/', cmd[0]);
			execve((pix->paths)[i], cmd, envp);
			i++;
		}
		destroy(pix->paths, pix);
	}
	else if (cmd_check(cmd) == 0)
	{
		execve(cmd[0], cmd, envp);
		destroy(pix->paths, pix);
	}
	exit(0);
}

void	firstchild(t_pipex *pix, int *link, char **envp)
{
	dup2((pix->fd)[0], STDIN_FILENO);
	close((pix->fd)[0]);
	dup2(link[1], STDOUT_FILENO);
	close(link[1]);
	close(link[0]);
	close((pix->fd)[1]);
	if (pix->cmd[0])
	{
		execcmd(pix, envp, pix->cmd[0]);
	}
	destroy(pix->paths, pix);
	exit(0);
}

void	secondchild(t_pipex *pix, int *link, char **envp)
{
	dup2((pix->fd)[1], STDOUT_FILENO);
	close((pix->fd)[1]);
	dup2(link[0], STDIN_FILENO);
	close(link[0]);
	if (pix->cmd[pix->cmdsize])
	{
		execcmd(pix, envp, pix->cmd[pix->cmdsize]);
	}
	destroy(pix->paths, pix);
	exit(0);
}

void	halfchilds(t_pipex *pix, int *link, int i, char **envp)
{
	dup2(link[0], STDIN_FILENO);
	close(link[0]);
	dup2(link[1], STDOUT_FILENO);
	close(link[1]);
	close((pix->fd)[1]);
	if (pix->cmd[i])
	{
		execcmd(pix, envp, pix->cmd[i]);
	}
	destroy(pix->paths, pix);
	exit(0);
}
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

#include "pipex.h"

void	printer(char **cmd)
{
	ft_putstr_fd("cmd is invalid:", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd("\n", 2);
}

void	execcmd(t_pipex *pix, char **envp, char **cmd)
{
	int	i;

	i = 0;
	if (cmd_check(cmd) == 1 && (pix->paths))
	{
		while ((pix->paths)[i])
		{
			(pix->paths)[i] = ft_sup_join((pix->paths)[i], '/', cmd[0]);
			execve((pix->paths)[i], cmd, envp);
			i++;
		}
	}
	else if (cmd_check(cmd) == 0)
		execve(cmd[0], cmd, envp);
	free(pix->pid);
	printer(cmd);
	destroy(pix->paths, pix);
	exit(0);
}

void	terminate(t_pipex *pix)
{
	closepipe(pix->link, pix);
	destroy(pix->paths, pix);
	free(pix->pid);
	exit(0);
}

void	firstchild(t_pipex *pix, int *link, char **envp)
{
	if (pix->fd[0] < 0)
	{
		if (pix->fd[1] >= 0)
			close((pix->fd)[1]);
		terminate(pix);
	}
	dup2((pix->fd)[0], STDIN_FILENO);
	close((pix->fd)[0]);
	dup2(link[1], STDOUT_FILENO);
	if (pix->fd[1] >= 0)
		close((pix->fd)[1]);
	closepipe(pix->link, pix);
	if (!pix->cmd[0])
	{
		ft_putstr_fd("cmd is empty\n", 2);
		destroy(pix->paths, pix);
		free(pix->pid);
		exit(0);
	}
	if (pix->cmd[0])
		execcmd(pix, envp, pix->cmd[0]);
	destroy(pix->paths, pix);
	free(pix->pid);
	exit(0);
}

void	secondchild(t_pipex *pix, int *link, char **envp)
{
	if (pix->fd[1] < 0)
		terminate(pix);
	dup2((pix->fd)[1], STDOUT_FILENO);
	close((pix->fd)[1]);
	dup2(link[0], STDIN_FILENO);
	closepipe(pix->link, pix);
	if (!pix->cmd[pix->cmdsize - 1])
	{
		ft_putstr_fd("cmd is empty\n", 2);
		destroy(pix->paths, pix);
		free(pix->pid);
		exit(0);
	}
	if (pix->cmd[(pix->cmdsize - 1)])
		execcmd(pix, envp, pix->cmd[(pix->cmdsize - 1)]);
	destroy(pix->paths, pix);
	free(pix->pid);
	exit(0);
}

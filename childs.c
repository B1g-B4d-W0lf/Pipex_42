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

void	firstchild(t_pipex pix, char **argv, int *link)
{
	int	i;

	i = 0;
	dup2(pix.fd[0], STDIN_FILENO);
	close(pix.fd[0]);
	dup2(link[1], STDOUT_FILENO);
	close(link[1]);
	close(link[0]);
	close(pix.fd[1]);
	printf("here");
	if (cmd_check(pix.cmd1) == 1)
	{
		while (pix.paths[i])
		{
			pix.paths[i] = ft_sup_join(pix.paths[i], '/', pix.cmd1[0]);
			execve(pix.paths[i], pix.cmd1, NULL);
			free(pix.paths[i]);
			i++;
		}
	}
	else 
		execve(pix.cmd1[1], pix.cmd2, NULL);
	exit(0);
}

void	secondchild(t_pipex pix, char **argv, int *link)
{
	int	i;

	i = 0;
	dup2(pix.fd[1], STDOUT_FILENO);
	close(pix.fd[1]);
	dup2(link[0], STDIN_FILENO);
	close(link[0]);
	if (cmd_check(pix.cmd2) == 1)
	{
		while (pix.paths[i])
		{
			pix.paths[i] = ft_sup_join(pix.paths[i], '/', pix.cmd2[0]);
			execve(pix.paths[i], pix.cmd2, NULL);
			free(pix.paths[i]);
			i++;
		}
	}
	else 
		execve(pix.cmd2[1], pix.cmd2, NULL);
	exit(0);
}
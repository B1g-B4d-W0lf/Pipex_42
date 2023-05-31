/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeges_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:48:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/31 22:58:56 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		closeone(link[i]);
		free(link[i]);
		i++;
	}
	free(link);
}

void	closeone(int *link)
{
	close(link[0]);
	close(link[1]);
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

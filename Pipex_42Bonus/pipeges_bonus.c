/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeges_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:48:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/06/01 20:24:08 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**createpipe(t_pipex *pix)
{
	int	j;
	int	**link;

	j = 0;
	link = malloc(pix->cmdsize * sizeof(int *));
	if (!link)
		return(NULL);
	while (j < pix->cmdsize)
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

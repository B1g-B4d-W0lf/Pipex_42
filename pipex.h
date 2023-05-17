/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:53:17 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/17 03:52:03 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
#include <sys/wait.h>
# include "./Libft/libft.h"

typedef struct s_pipex
{
	char	**paths;
	int		fd[2];
	char	**cmd1;
	char	**cmd2;
}		t_pipex;

//utils.c
char	*ft_sup_join(char *s1, char c, char *s2);
void	freetab(char **tab);
int	cmd_check(char **cmd);

//pipex.c
//childs.c
void	firstchild(t_pipex pix, char **argv, int *link);
void	secondchild(t_pipex pix, char **argv, int *link);
#endif
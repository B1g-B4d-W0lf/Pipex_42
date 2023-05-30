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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <sys/wait.h>
# include "./Libft/libft.h"

typedef struct s_pipex
{
	char	**paths;
	int		fd[2];
	char	***cmd;
	int		hd;
	int		cmdsize;
}		t_pipex;

//utils.c
char	*ft_sup_join(char *s1, char c, char *s2);
void	freetab(char **tab);
int		cmd_check(char **cmd);
void	destroy(char **paths, char ***cmd);

//pipex.c
void	pipex(t_pipex *pix, char **envp);
void	parse(int argc, char **argv, char **envp, t_pipex *pix);

//childs.c
void	firstchild(t_pipex *pix, int *link, char **envp);
void	secondchild(t_pipex *pix, int *link, char **envp);
void	halfchilds(t_pipex *pix, int *link, int i, char **envp);

//parsing.c
void	cmdges(char **argv, t_pipex *pix);
char	**findpath(char **envp);

#endif
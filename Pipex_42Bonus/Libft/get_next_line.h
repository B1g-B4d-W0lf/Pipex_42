/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:04:16 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/23 02:35:20 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct g_list
{
	char			*content;
	struct g_list	*next;
}					t_lstb;

t_lstb	*ft_lstnewnew(char *content, t_lstb *lst, int boolean);
char	*ft_lstaddback(t_lstb **lst, t_lstb *new, char *west, int boolean);
int		ft_strlenfree(char *str, t_lstb *tab, int boolean);
int		ft_lstiternew(t_lstb *lst, int (*f)(char *, t_lstb *tab, int boolean));
char	*fillstr(t_lstb *tab, int index);
char	*get_next_line(int fd);
int		checkbuffer(char c, char const *set);
char	*readit(int fd, char *west, t_lstb **tab);
int		writetemp(char *temp, char *str, int boolean);
char	*westigation(char *west, char *buffer, t_lstb **tab, int boolean);

#endif
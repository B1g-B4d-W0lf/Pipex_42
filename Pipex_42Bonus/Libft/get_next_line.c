/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/23 02:33:11 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fillstr(t_lstb *tab, int index)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((index + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	while (tab)
	{
		while (tab->content[j])
		{
			str[i] = tab->content[j];
			i++;
			j++;
		}
		tab = tab->next;
		j = 0;
	}
	str[i] = '\0';
	return (str);
}

int	writetemp(char *temp, char *str, int boolean)
{
	int		i;

	i = 0;
	if (!boolean)
	{
		while (str[i])
		{
			temp[i] = str[i];
			i++;
		}
		temp[i] = '\0';
		return (0);
	}
	while (str[i] != '\n' && str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = str[i];
	if (temp[i] == '\n')
	{
		i++;
		temp[i] = '\0';
	}
	return (i);
}

char	*westigation(char *west, char *buffer, t_lstb **tab, int boolean)
{
	char	*temp;
	int		i;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	if (!boolean)
	{
		i = writetemp(temp, buffer, 1);
		ft_lstaddback(tab, ft_lstnewnew(temp, 0, 1), 0, 0);
		if (buffer[i] != '\0')
		{
			west = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (west == NULL)
				return (NULL);
			writetemp(west, &buffer[i], 0);
		}
		return (free(temp), west);
	}
	i = writetemp(temp, west, 1);
	ft_lstaddback(tab, ft_lstnewnew(temp, 0, 1), 0, 0);
	writetemp(west, &west[i], 0);
	return (free(temp), west);
}

char	*readit(int fd, char *west, t_lstb **tab)
{
	char	*buffer;
	int		output;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	output = read(fd, buffer, BUFFER_SIZE);
	if (output < 0)
		return (free(buffer), NULL);
	buffer[output] = '\0';
	while (checkbuffer('\n', buffer) != 1 && output != 0)
	{
		ft_lstaddback(tab, ft_lstnewnew(buffer, 0, 1), 0, 0);
		output = read(fd, buffer, BUFFER_SIZE);
		buffer[output] = '\0';
	}
	if (checkbuffer('\n', buffer) == 1)
	{
		west = westigation(west, buffer, tab, 0);
	}
	return (free(buffer), west);
}

char	*get_next_line(int fd)
{
	t_lstb		*tab;
	static char	*west = NULL;
	char		*string;
	int			i;

	string = NULL;
	tab = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (west != NULL)
	{
		west = westigation(west, 0, &tab, 1);
		if (west[0] == '\0')
			west = ft_lstaddback(0, 0, west, 1);
	}
	if (west == NULL && (tab == NULL || checkbuffer('\n', tab->content) == 0))
		west = readit(fd, west, &tab);
	if (tab == NULL)
		return (NULL);
	i = ft_lstiternew(tab, &ft_strlenfree);
	string = fillstr(tab, i);
	ft_strlenfree(0, tab, 0);
	return (string);
}

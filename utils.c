/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:26:44 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/17 03:55:58 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_check(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("here");
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (cmd[i][j] == '/')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	*whilenorm(char *str, char *s2, int *tab)
{
	while (s2[tab[3]])
	{
		str[tab[2] + tab[3]] = s2[tab[3]];
		tab[3]++;
	}
	str[tab[2] + tab[3]] = '\0';
	return (str);
}

char	*ft_sup_join(char *s1, char c, char *s2)
{
	char	*str;
	int		tab[5];

	if (!s1 || !s2)
		return (0);
	tab[0] = ft_strlen((char *) s1);
	tab[1] = ft_strlen((char *) s2);
	str = malloc((tab[0] + tab[1]) * sizeof (char) + 2);
	if (str == NULL)
		return (NULL);
	tab[2] = 0;
	tab[3] = 0;
	while (s1[tab[2]])
	{
		str[tab[2]] = s1[tab[2]];
		tab[2]++;
	}
	str[tab[2]] = c;
	tab[2]++;
	str = whilenorm(str, s2, tab);
	return (str);
}

void	freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

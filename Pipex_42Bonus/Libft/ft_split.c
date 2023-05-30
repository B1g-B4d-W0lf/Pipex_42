/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:14:24 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/28 21:29:15 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **str, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	strcount(char *s, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			index++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (index);
}

static char	*createstr(char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start <= end && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*checkchar(char *s, char c)
{
	int		i;
	char	*tab;
	int		start;
	int		end;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == 0)
			return (0);
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i - 1;
		tab = createstr(s, start, end);
		return (tab);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		tab_i[2];
	char	**tab;

	if (!s)
		return (NULL);
	tab_i[0] = 0;
	tab_i[1] = strcount((char *) s, c);
	tab = malloc((tab_i[1] + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (*s && tab_i[0] < tab_i[1])
	{
		if (*s != c && *s)
		{
			tab[tab_i[0]] = checkchar((char *)s, c);
			if (!tab[tab_i[0]++])
				return (ft_free(tab, tab_i[1]));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	tab[tab_i[0]] = NULL;
	return (tab);
}

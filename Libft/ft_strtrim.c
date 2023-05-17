/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:26:18 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/24 18:46:56 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	checkstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (checkset(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

static int	checkend(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen((char *) s1) - 1;
	while (checkset(s1[i], set) == 1 && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1)
		return (0);
	i = 0;
	start = checkstart(s1, set);
	end = checkend(s1, set);
	if (start > end)
		return (ft_calloc(1, 1));
	str = malloc((end - start + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (!set)
		return (NULL);
	while (start <= end && s1[start])
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

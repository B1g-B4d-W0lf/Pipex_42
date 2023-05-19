/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:55:36 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/24 18:40:09 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		tab[5];

	if (!s1 || !s2)
		return (0);
	tab[0] = ft_strlen((char *) s1);
	tab[1] = ft_strlen((char *) s2);
	str = malloc((tab[0] + tab[1]) * sizeof (char) + 1);
	if (str == NULL)
		return (NULL);
	tab[2] = 0;
	tab[3] = 0;
	while (s1[tab[2]])
	{
		str[tab[2]] = s1[tab[2]];
		tab[2]++;
	}
	while (s2[tab[3]])
	{
		str[tab[2] + tab[3]] = s2[tab[3]];
		tab[3]++;
	}
	str[tab[2] + tab[3]] = '\0';
	return (str);
}

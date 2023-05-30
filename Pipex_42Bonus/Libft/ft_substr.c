/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:18:02 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/23 23:15:57 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	tab[2];

	if (!s)
		return (0);
	tab[0] = ft_strlen((char *)s);
	tab[1] = start;
	if (tab[1] >= tab[0])
	{
		str = ft_strdup("");
		return (str);
	}
	if (len > (tab[0] - tab[1]))
		len = (tab[0] - tab[1]);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	tab[0] = 0;
	while (s[tab[1]] && tab[0] < len)
	{
		str[tab[0]++] = s[tab[1]++];
	}
	str[tab[0]] = '\0';
	return (str);
}

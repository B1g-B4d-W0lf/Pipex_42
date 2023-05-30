/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:16:26 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/21 18:38:20 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	littlelen;
	char	*bigstr;

	if (!big && !len)
		return (NULL);
	bigstr = (char *)big;
	i = 0;
	j = 0;
	littlelen = ft_strlen((char *)little);
	if ((!littlelen && !len) || big == little)
		return (bigstr);
	while (bigstr[i] && (i + littlelen) <= len)
	{
		while (bigstr[i + j] == little[j] && little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return (bigstr + i);
		i++;
		j = 0;
	}
	return (NULL);
}

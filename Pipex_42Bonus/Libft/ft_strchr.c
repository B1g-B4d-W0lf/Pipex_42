/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:15:41 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/21 17:42:23 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((char) c == str[i])
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *)&str[i]);
	return (NULL);
}

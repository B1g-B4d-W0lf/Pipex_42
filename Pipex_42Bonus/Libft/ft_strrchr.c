/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:16:35 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/21 18:31:20 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (((char *)str)[i])
		i++;
	while (i > 0)
	{
		if (((char *)str)[i] == (char) c)
			return (((char *)str) + i);
		i--;
	}
	if (str[i] == (char) c)
		return ((char *)&str[i]);
	return (NULL);
}

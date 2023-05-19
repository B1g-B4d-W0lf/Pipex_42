/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:14:51 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/21 17:41:12 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size )
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)memoryBlock;
	while (i < size)
	{
		if (str[i] == (char) searchedChar)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

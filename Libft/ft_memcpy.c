/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:15:20 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/19 04:51:49 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destb;
	const unsigned char	*srcb;
	size_t				len;

	if (!dest && !src)
		return (0);
	destb = dest;
	srcb = src;
	len = 0;
	while (len < n)
	{
		destb[len] = srcb[len];
		len++;
	}
	return (dest);
}

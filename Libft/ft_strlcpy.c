/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:16:12 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/19 18:58:46 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	dstlen;
	size_t	srclen;

	len = 0;
	dstlen = size;
	srclen = ft_strlen((char *)src);
	if (!dstlen || !src || !dst)
		return (srclen);
	if (dstlen != 0)
	{
		while (src[len] && len < (dstlen - 1))
		{
			dst[len] = src[len];
			len++;
		}
	}
	dst[len] = '\0';
	return (srclen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:15:57 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/24 23:02:07 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	if (!dst && !size)
		return (0);
	len = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (!size)
		return (srclen);
	if (size <= dstlen)
		return (srclen + size);
	while (src[len] && (len < size - dstlen - 1))
	{
		dst[dstlen + len] = src[len];
		len++;
	}
	dst[dstlen + len] = '\0';
	return (srclen + dstlen);
}

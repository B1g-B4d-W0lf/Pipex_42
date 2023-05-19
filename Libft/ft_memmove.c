/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:15:29 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/19 04:53:50 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destb;
	char		*srcb;
	size_t		len;

	destb = (char *)dest;
	srcb = (char *)src;
	len = 0;
	if (destb == NULL && srcb == NULL)
		return (NULL);
	if (destb > srcb)
	{
		while (n-- > 0)
			destb[n] = srcb[n];
	}
	else
	{
		while (len < n)
		{
			destb[len] = srcb[len];
			len++;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:14:59 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/17 22:14:41 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)pointer1;
	str2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size && str1[i] == str2[i])
		i++;
	if (i == size)
		return (0);
	return (str1[i] - str2[i]);
}

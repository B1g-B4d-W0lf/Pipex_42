/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:13:56 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/28 21:29:04 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*str;

	if (elementSize >= SIZE_MAX || elementCount >= SIZE_MAX)
		return (NULL);
	str = malloc(elementCount * elementSize);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, elementCount * elementSize);
	return (str);
}

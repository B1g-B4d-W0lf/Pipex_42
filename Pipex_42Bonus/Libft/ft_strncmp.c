/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:16:22 by wfreulon          #+#    #+#             */
/*   Updated: 2022/11/19 05:04:31 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;

	t = 0;
	if (n == 0)
		return (0);
	while (s1[t] && s2[t] && s1[t] == s2[t] && t < n - 1)
		t++;
	return ((unsigned char)s1[t] - (unsigned char)s2[t]);
}

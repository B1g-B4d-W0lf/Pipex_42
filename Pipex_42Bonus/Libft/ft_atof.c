/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:40:32 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/11 23:13:04 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	postcomma(float *f, int *i, char *str)
{
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		f[1] = f[1] + (str[*i] - 48) * f[3];
		f[3] = f[3] * 0.1;
		(*i)++;
	}
}

float	ft_atof(char *str)
{
	int		i;
	float	f[4];

	f[3] = 0.1;
	f[1] = 0.;
	f[0] = 0;
	f[2] = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f[2] = f[2] * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		f[0] = f[0] * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		postcomma(f, &i, str);
	f[0] = (f[0] + f[1]) * f[2];
	return (f[0]);
}

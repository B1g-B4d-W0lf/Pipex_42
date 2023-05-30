/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:57:51 by wfreulon          #+#    #+#             */
/*   Updated: 2023/01/25 22:51:22 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_hexa(unsigned int n, int c, int *len)
{
	if (n >= 16)
		ft_putnbr_hexa(n / 16, c, len);
	ft_putchar(HEXA[n % 16 + c * 16]);
	return (*len += 1);
}

int	ft_putnbr(int n, int *len)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		*len += ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, len);
	ft_putchar(48 + nb % 10);
	return (*len += 1);
}

int	ft_putnbr_u(unsigned int n, int *len)
{
	unsigned long long	nb;

	nb = n;
	if (nb >= 10)
		ft_putnbr_u(nb / 10, len);
	ft_putchar(48 + nb % 10);
	return (*len += 1);
}

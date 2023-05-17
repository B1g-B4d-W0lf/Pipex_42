/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:57:42 by wfreulon          #+#    #+#             */
/*   Updated: 2023/01/25 23:10:51 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_p(unsigned long long n, int *len)
{
	if (n >= 16)
		ft_putnbr_p(n / 16, len);
	ft_putchar(HEXA[n % 16]);
	return (*len += 1);
}

int	ft_print_p(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		len = ft_putstr("(nil)");
	else
	{
		len = ft_putstr("0x");
		ft_putnbr_p(ptr, &len);
	}
	return (len);
}

int	triage(char c, va_list ptr)
{
	int	len;

		len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		len += ft_print_p(va_arg(ptr, unsigned long long));
	else if (c == 'd')
		ft_putnbr(va_arg(ptr, int), &len);
	else if (c == 'i')
		ft_putnbr(va_arg(ptr, int), &len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ptr, unsigned int), &len);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hexa(va_arg(ptr, unsigned int), (c == 'X'), &len);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ptr, str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += triage(str[i + 1], ptr);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}

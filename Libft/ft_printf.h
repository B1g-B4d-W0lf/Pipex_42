/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:57:58 by wfreulon          #+#    #+#             */
/*   Updated: 2023/01/25 22:51:08 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define HEXA "0123456789abcdef0123456789ABCDEF"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_hexa(unsigned int n, int c, int *len);
int	ft_putnbr(int n, int *len);
int	ft_putnbr_p(unsigned long long n, int *len);
int	ft_print_p(unsigned long long ptr);
int	triage(char c, va_list ptr);
int	ft_printf(const char *str, ...);
int	ft_putnbr_u(unsigned int n, int *len);

#endif
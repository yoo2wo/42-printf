/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:09:35 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/10 12:13:00 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	rec_nbr(long long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	rec_nbr(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr(long long n, int len, char *base)
{
	long long nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	rec_nbr(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	rec_p(unsigned long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	rec_p(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr_p(unsigned long nbr, int len, char *base)
{
	rec_p(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res > LONG_MAX && sign == 1)
		return (-1);
	if (res - 1 > LONG_MAX && sign == -1)
		return (0);
	return (res * sign);
}

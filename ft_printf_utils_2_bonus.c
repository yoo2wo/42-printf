/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:09:35 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/15 16:21:59 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	rec_nbr(long long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	rec_nbr(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr(long long n, int len, char *base)
{
	long long	nbr;

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

int	num_size_p(unsigned long num, int base_len)
{
	int	size;

	if (num == 0)
		return (1);
	size = 0;
	while (num > 0)
	{
		num /= base_len;
		size++;
	}
	return (size);
}

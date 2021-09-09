/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:57:43 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/09 15:05:08 by jayoo            ###   ########.fr       */
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

void	print_zero(int zero, int len)
{
	if (zero == 1)
		putnchar(len, '0');
	else
		putnchar(len, ' ');
}

void	d_print_right(t_format info, long d, int d_len, int minus)
{
	putnchar(info.width - info.precision - minus, ' ');
	if (minus == 1)
		write(1, "-", 1);
	putnchar(info.precision - d_len, '0');
	ft_putnbr(d, 10, DEC);
}

void	d_print_left(t_format info, long d, int d_len, int minus)
{
	if (minus == 1)
		write(1, "-", 1);
	putnchar(info.precision - d_len, '0');
	ft_putnbr(d, 10, DEC);
	putnchar(info.width - info.precision - minus, ' ');

}

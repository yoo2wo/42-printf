/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:14:09 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/10 12:14:47 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

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

void	x_print_left(t_format info, unsigned long num, int size, char *base)
{
	putnchar(info.precision - size, '0');
	ft_putnbr(num, 16, base);
	putnchar(info.width - info.precision, ' ');

}

void	x_print_right(t_format info, unsigned long num, int size, char *base)
{
	putnchar(info.width - info.precision, ' ');
	putnchar(info.precision - size, '0');
	ft_putnbr(num, 16, base);
}

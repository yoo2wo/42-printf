/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:43:05 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/09 14:53:02 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	p_print_right(t_format info, unsigned long num, int size)
{
	putnchar(info.width - info.precision - 2, ' ');
	ft_putstr("0x");
	putnchar(info.precision - size, '0');
	if (size)
		ft_putnbr_p(num, 16, HEX_LOW);
}

void	p_print_left(t_format info, unsigned long num, int size)
{
	ft_putstr("0x");
	putnchar(info.precision - size, '0');
	if (size)
		ft_putnbr_p(num, 16, HEX_LOW);
	putnchar(info.width - info.precision - 2, ' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:14:09 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/13 15:43:09 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

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

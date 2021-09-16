/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/15 19:06:56 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_arg_c(va_list ap, t_format info)
{
	char	c;
	int		len;

	if (info.width > 1)
		len = info.width;
	else
		len = 1;
	c = (char)va_arg(ap, int);
	if (info.left == 1)
	{
		write(1, &c, 1);
		putnchar(len - 1, ' ');
	}
	else
	{
		putnchar(len - 1, ' ');
		write(1, &c, 1);
	}
	return (len);
}

int	get_arg_s(va_list ap, t_format info)
{
	char	*str;
	int		str_len;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	if (info.precision > str_len || info.precision <= -1)
		info.precision = str_len;
	if (info.width - info.precision <= 0)
		write(1, str, info.precision);
	else if (info.left == 0)
	{
		print_zero(info.zero, info.width - info.precision);
		write(1, str, info.precision);
	}
	else if (info.left == 1)
	{
		write(1, str, info.precision);
		putnchar(info.width - info.precision, ' ');
	}
	if (info.width > info.precision)
		return (info.width);
	else
		return (info.precision);
}

int	get_arg_d(va_list ap, t_format info)
{
	int	minus;
	int	d;
	int	d_len;

	minus = 0;
	d = va_arg(ap, int);
	if (d < 0)
		minus = 1;
	if (d == 0 && info.precision == 0)
	{
		putnchar(info.width, ' ');
		return (info.width);
	}
	d_len = num_size(d, 10);
	if (info.zero && info.precision <= -1)
		info.precision = info.width - minus;
	if (info.precision <= -1 || info.precision < d_len)
		info.precision = d_len;
	if (info.left == 0)
		d_print_right(info, d, d_len, minus);
	else
		d_print_left(info, d, d_len, minus);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision + minus);
}

int	get_arg_u(va_list ap, t_format info)
{
	int				len;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	len = num_size(num, 10);
	if (num == 0 && info.precision == 0)
	{
		putnchar(info.width, ' ');
		return (info.width);
	}
	if (info.zero && info.precision <= -1)
		info.precision = info.width;
	if (info.precision <= -1 || info.precision < len)
		info.precision = len;
	if (info.left == 1)
		d_print_left(info, num, len, 0);
	else
		d_print_right(info, num, len, 0);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision);
}

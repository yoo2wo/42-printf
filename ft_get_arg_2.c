/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:02:21 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/09 16:26:06 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	get_arg_p(va_list ap, t_format info)
{
	unsigned long	num;
	int				nbr_size;

	num = (unsigned long)va_arg(ap, void *);
	nbr_size = num_size(num, 16);//num_size_p 굳이 사용하지않아도된다.
	if (info.precision == 0 && num == 0)
		nbr_size--; //원래는 0이여도 1자리를 출력해야하는데 이경우는 아예 출력x
	if (info.precision <= -1 || info.precision < nbr_size) // 이부분 다시보기
		info.precision = nbr_size;
	if (info.width < info.precision + 2)
		info.width = info.precision + 2;
	if (info.left == 0)
		p_print_left(info, num, nbr_size);
	else
		p_print_right(info, num, nbr_size);
	return (info.width);
}


int		get_arg_per(va_list ap, t_format info)
{
	int len;

	len = 1;
	if (info.width > 1)
		len = info.width;
	if (info.left == 1)
	{
		write(1, "%", 1);
		putnchar(len - 1, ' ');
	}
	else
	{
		print_zero(info.zero, len - 1);
		write(1, "%", 1);
	}
	return (len);
}

int		get_arg_x(va_list ap, t_format info, char *base)
{
	unsigned int 	num;
	int 			nbr_size;

	num = va_arg(ap, unsigned int);
	nbr_size = num_size(num, 16);
	if (info.precision == 0 && num == 0) //p 일때 신경 안써줬나?
	{
		print_zero(info.zero, info.width);
		return (info.width);
	}
	if (info.precision <= -1 || info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.left == 1)
		x_print_left(info, num, nbr_size, base);
	else
		x_print_right(info, num, nbr_size, base);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision);
}

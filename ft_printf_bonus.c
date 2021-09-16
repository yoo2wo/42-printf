/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/16 13:54:53 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_arg(va_list ap, t_format info, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = get_arg_c(ap, info);
	else if (c == 's')
		length = get_arg_s(ap, info);
	else if (c == 'p')
		length = get_arg_p(ap, info);
	else if (c == 'd' || c == 'i')
		length = get_arg_d(ap, info);
	else if (c == 'u')
		length = get_arg_u(ap, info);
	else if (c == 'x')
		length = get_arg_x(ap, info, HEX_LOW);
	else if (c == 'X')
		length = get_arg_x(ap, info, HEX_UP);
	else if (c == '%')
		length = get_arg_per(info);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			cnt += set_format(ap, (char *)str, &i);
		}
		else
		{
			write(1, &str[i], 1);
			cnt++;
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}

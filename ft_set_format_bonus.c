/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:11:46 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/15 16:16:07 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	valid_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	init_info(t_format *info)
{
	info->zero = 0;
	info->left = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = -1;
}

int	get_number(char *str, int *idx)
{
	int	i;
	int	result;

	i = *idx;
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	i--;
	*idx = i;
	return (result);
}

void	set_format_num(t_format *info, char *str, int *i)
{
	int	num;

	num = get_number(str, i);
	if (info->dot == 0)
		info->width = num;
	else
		info->precision = num;
}

int	set_format(va_list ap, char *str, int *i)
{
	t_format	info;

	init_info(&info);
	while (valid_char(str[*i], TYPE) == -1)
	{
		if (str[*i] == '0')
			info.zero = 1;
		if (str[*i] == '-')
			info.left = 1;
		if (str[*i] == '.')
		{
			info.dot = 1;
			info.precision = 0;
		}
		if (valid_char(str[*i], DEC) != -1 && str[*i] != '0')
			set_format_num(&info, str, i);
		(*i)++;
	}
	if (info.left == 1)
		info.zero = 0;
	return (get_arg(ap, info, str[*i]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:32:01 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/20 15:35:04 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> //long_max

int	ft_isdigit(int c);
int	ft_isspace(int c);

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
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

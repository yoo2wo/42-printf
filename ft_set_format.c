/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:11:46 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/09 15:14:15 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_star(va_list ap, t_format *info)//플래그 *인 경우 처리
{
	int tmp;

	tmp = va_arg(ap, int);
	if (info->dot == 0) //.있을때
	{
		if (tmp > 0)
			info->width = tmp;
		else if (tmp < 0)
		{
			tmp *= -1;
			info->left = 1;
			info->width = tmp;
		}
		else
			info->zero = 0;
	}
	else
	{
		if (tmp >= 0)
			info->precision = tmp;
		else
			info->precision = -2;
	}
}
void	set_format_num(t_format *info, char *str, int *i)
{
	int num;

	num = ft_atoi(str + (*i));
	if (info->dot == 0)
		info->width = num;
	else
		info->precision = num;
}

int		set_format(va_list ap, char *str, int *i) //t_format의 값을 설정
{
	t_format	info;

	init_info(&info);//info 초기화 함수 (주소로 주어야 동일한 info를 가르킨다.)

	while (valid_char(str[*i], TYPE) == -1)//반복적으로 체크하기 다음 문자열이 올때 까지 => 괄호안에 함수를 넣어야한다.
	{
		if (str[*i] == '0')
			info.zero = 1;
		if (str[*i] == '-')
			info.left = 1;
		if (str[*i] == '.')
		{
			info.dot = 1;
			info.precision = 0; //❓초기화값과 지금 할당값 다시 확인하기
		}
		if (str[*i] == '*')
		{
			info.width = 1; //*인 경우 다음 인자를 처리 ❓이 코드 꼭 필요한가?
			set_format_star(ap, &info);
		}
		if (valid_char(str[*i], DEC) != -1 && str[*i] != '0')
			set_format_num(&info, str, i);
		(*i)++;
	}
	return (get_arg(ap, info, str[*i]));
}

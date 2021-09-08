/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/08 16:54:07 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		valid_char(char c, char *str) //서식 문자열을 만났는지 확인
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void		init_info(t_format *info)
{
	info->zero = 0;
	info->left = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = 0;
}

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

	// if (num = ft_atoi(str + *i) < 0)
	// 	num *= -1;
	num = ft_atoi(str + (*i));
	if (info->dot == 0)
		info->width = num;
	else
		info->precision = num;
}

int		get_arg(va_list ap, t_format info, char c)
{
	int length;

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
		length = get_arg_x(ap, info);
	else if(c == 'X')
		length = get_arg_X(ap,info);
	else if(c == '%')
		length = get_arg_per(ap, info);
	return (length);
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
			info.precision = 1; //❓초기화값과 지금 할당값 다시 확인하기
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
//	printf("info : %d %d %d %d %d\n", info.zero, info.left, info.width, info.dot, info.precision);
	return (get_arg(ap, info, str[*i]));
}

int		ft_printf(const char *str, ...)
{
	va_list 	ap; //가변 인자 목록
	int 		i;
	int 		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, str); //문자열을 넣으면 문자의 개수를 구해 포인터를 설정한다.
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			cnt += set_format(ap, (char *)str, &i);
			//cnt += get_arg(ap, (char *)str, &i); // 이 함수에서 해당 변수 문자 개수 세어주고, i 값 증가시켜주고, 해당 변수 출력하기
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

int main()
{
	char c = 'a';
	int a = -10;
	int b = 11;
	char *s = "abcdef";

	ft_printf("hi a is %07d//, %07d and name is %-3c//\n", a, b, c);
	ft_printf("%8d//\n", a);
	ft_printf("%010s//\n", s);
	ft_printf("%010%//\n");
	ft_printf("%-10%//\n");

	ft_printf("%10.5i//\n", b);
	return 0;
}

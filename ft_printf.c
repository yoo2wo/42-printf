/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/09 16:26:46 by jayoo            ###   ########.fr       */
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
	info->precision = -1;
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
		length = get_arg_x(ap, info, HEX_LOW);
	else if(c == 'X')
		length = get_arg_x(ap, info, HEX_UP);
	else if(c == '%')
		length = get_arg_per(ap, info);
	return (length);
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
	int n  = -1;
	char *s = "abcdef";
	int *p;
	int *q;

	p = &a;


	ft_printf("hi a is %07d//, %07d and name is %-3c//\n", a, b, c);
	ft_printf("%8d//\n", a);
	ft_printf("%010s//\n", s);
	ft_printf("%010%//\n");
	ft_printf("%-10%//\n");

	ft_printf("%10.5i//\n", b);
	ft_printf("%10u//\n", n);
	printf("%p//\n", p);
	ft_printf("%p//\n", p);

	return 0;
}

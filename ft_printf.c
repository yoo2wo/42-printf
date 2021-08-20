/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/20 14:10:12 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define TYPE "cspdiuxX%"

typedef struct 	s_format
{
	int			zero;
	int			left;
	int			width;
	int			dot;
	int			precision;
}				t_format;

int 	get_arg_c(va_list ap, char *str, int  *i);
int 	get_arg_d(va_list ap, char *str, int  *i);
int 	get_arg_p(va_list ap, char *str, int  *i);

int		get_arg(va_list ap, char *str, int *i)
{
	char c;
	int length;

	if (str[*i] == 'c')
		length = get_arg_c(ap, str, i);
	else if (str[*i] == 'd')
		length = get_arg_d(ap, str, i);
	else if (str[*i] == 'p')
		length = get_arg_p(ap, str, i);
	return (length);
}

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

void	set_format_width(va_list ap, t_format *info)//플래그 *인 경우 처리
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
		if (tmp > 0)
			info->precision = tmp;
		else
			info->precision = -2;
	}
}

int		set_format(va_list ap, char *str, int *i) //t_format의 값을 설정
{
	t_format	info;

	init_info(&info);//info 초기화 함수 (주소로 주어야 동일한 info를 가르킨다.)

	while (valid_char(str[*i], TYPE) == -1)//반복적으로 체크하기 다음 문자열이 올때 까지 => 괄호안에 함수를 넣어야한다.
	{
		if (str[*i] == 0)
			info.zero = 1;
		if (str[*i] == '-')
			info.left = 1;
		if (str[*i] == '.')
		{
			info.dot = 1;
			info.precision = 1; //❓초기화값과 지금 할당값 다시 확인하기
		}
		if (str[*i] == '*')
			info.width = 1; //*인 경우 다음 인자를 처리 ❓이 코드 꼭 필요한가?
			set_format_width(ap, &info);
		//❓if (str[*i] == 숫자) //숫자인경우 처리
		(*i)++;
	}
	printf("info : %d %d %d %d %d\n", info.zero, info.left, info.width, info.dot, info.precision);
	return (get_arg(ap, (char *)str, i));
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

	int a = 10;
	//ft_printf("sta %c sdfa %d fi %c and %p", 'A', 3, 'C', a);
	ft_printf("hi a is %*d//\n", 5, a);

	return 0;
}

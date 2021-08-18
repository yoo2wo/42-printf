/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/18 21:39:17 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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

int		set_format(va_list ap, char *str, int *i) //t_format의 값을 설정
{
	t_format	info;

	//info 초기화 함수

	while ()//반복적으로 체크하기 다음 문자열이 올때 까지 => 괄호안에 함수를 넣어야한다.
	{
		if (str[*i] == 0)
			info.zero = 1;
		if (str[*i] == '-')
			info.left = 1;
		if (str[*i] == '.')
		{
			info.dot = 1;
			info.precision = 1;
		}
		if (str[*i] == '*')
			info.width == 1; //*인 경우 다음 인자를 처리
		//if (str[*i] == 숫자) //숫자인경우 처리
	}
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
			cnt += get_format(ap, (char *)str, &i);
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
	int a;
	ft_printf("sta %c sdfa %d fi %c and %p", 'A', 3, 'C', a);
	return 0;
}

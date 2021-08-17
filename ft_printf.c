/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/17 15:29:58 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		// fs = ft_strchr('%');
		// if (++fs == 'd')
		// 	arr[i] = va_arg(ap, int);
		// else if (fs == 'c')
		// 	arr[i] = va_arg(ap, char);
		// else if (fs == 's')
		// 	arr[i] = va_arg(ap, char *);
		// else if (fs == 'p')
		// 	arr[i] = va_arg(ap, void *);

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
			cnt += get_arg(ap, (char *)str, &i); // 이 함수에서 해당 변수 문자 개수 세어주고, i 값 증가시켜주고, 해당 변수 출력하기
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

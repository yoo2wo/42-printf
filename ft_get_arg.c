/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/21 17:22:40 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);

// get_arg_c(ap);
// get_arg_s(ap);
// get_arg_p(ap);
// get_arg_d(ap);
// get_arg_i(ap);
// get_arg_u(ap);
// get_arg_x(ap);
// get_arg_X(ap);
// get_arg_per(ap);

int 	get_arg_c(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int		get_arg_s(va_list ap)
{
	return (0);
}

int 	get_arg_p(va_list ap)
{
	void *p;

	p = va_arg(ap, void *);
	printf("%p\n", p);
	// 주소값 출력하는것 처리해주어야한다.
	return (1);
}

int		get_int_len(int d) //get_arg_d 에 있는 함수
{
	int i;

	i = 0;
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

int 	get_arg_d(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, 1);
	return (get_int_len(d));
}

///////////////////////////// 함수 개수 초과
int		get_arg_i(va_list ap)
{
	return (0);
}

int		get_arg_u(va_list ap)
{
	return (0);
}

int		get_arg_x(va_list ap)
{
	return (0);
}

int		get_arg_X(va_list ap)
{
	return (0);
}

int		get_arg_per(va_list ap)
{
	return (0);
}


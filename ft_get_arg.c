/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/23 16:29:01 by jayoo            ###   ########.fr       */
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

void putnchar(int num, char c) // get_arg_c 에서 사용하는 함수
{
	int i;

	i = 0;
	while (i < num)
	{
		write(1, &c, 1);
		i++;
	}
}

int 	get_arg_c(va_list ap, t_format info)
{
	char c;
	int len;

	if (info.width > 1)
		len = info.width;
	else
		len = 1;
	c = (char)va_arg(ap, int);
	if (info.left == 1)
	{
		write(1, &c, 1);
		putnchar(len - 1, ' ');
	}
	else
	{
		putnchar(len - 1, ' ');
		write(1, &c, 1);
	}
	return (len);
}

int		get_arg_s(va_list ap, t_format info)
{
	return (0);
}

int 	get_arg_p(va_list ap, t_format info)
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
	if (d < 0) //빼도된다.
	{
		i++;
		d *= -1;
	}
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

void	print_zero(int zero, int len)
{
	if (zero == 1)
		putnchar(len, '0');
	else
		putnchar(len, ' ');
}

int 	get_arg_d(va_list ap, t_format info)
{
	int d;
	int len;
	int wd;

	len = 0;
	d = va_arg(ap, int);
	if (d < 0)
	{
		d *= -1;
		write(1, "-", 1);
		len++;
	}
	len += get_int_len(d);
	wd = len;
	if (info.width > len)
		wd = info.width;
	if (info.left == 1)
		ft_putnbr_fd(d, 1);
	print_zero(info.zero, wd - len);
	if (info.left == 0)
		ft_putnbr_fd(d, 1);
	// if (info.left == 1)// info를 확인하고 상황에 맞게 출력하기 //norm 때문에 info.zero 부분 함수화 해야할수도
	// {
	// 	ft_putnbr_fd(d, 1);
	// 	print_zero(info.zero, wd - len);
	// 	// if (info.zero == 1)
	// 	// 	putnchar(wd - len, '0');
	// 	// else
	// 	// 	putnchar(wd - len, ' ');
	// }
	// else
	// {
	// 	print_zero(info.zero, wd - len);
	// 	ft_putnbr_fd(d, 1);
	// }
	return (wd);
}

///////////////////////////// 함수 개수 초과
int		get_arg_i(va_list ap, t_format info)
{
	return (0);
}

int		get_arg_u(va_list ap, t_format info)
{
	return (0);
}

int		get_arg_x(va_list ap, t_format info)
{
	return (0);
}

int		get_arg_X(va_list ap, t_format info)
{
	return (0);
}

int		get_arg_per(va_list ap, t_format info)
{
	return (0);
}


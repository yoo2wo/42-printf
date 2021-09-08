/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/08 16:53:54 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd);

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putnchar(int num, char c) // get_arg_c 에서 사용하는 함수
{
	int i;

	i = 0;
	while (i < num)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	rec(long long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	rec (nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr(long long n, int len, char *base)
{
	long long nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	rec(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
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
	char *str;
	int len;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (str == 0)//null일 경우 null print
		str = "(null)";
	if (info.precision <= -1 || info.precision >= len) //precision에 따라 출력길이 달라짐
		info.precision = len;
	if (info.width - info.precision <= 0)
	{
		write(1, str, info.precision);
		return (info.precision);
	}
	else if (info.left == 1)
	{
		write(1, str, len);
		putnchar(info.width - info.precision, ' ');
	}
	else
	{
		print_zero(info.zero, info.width - len);
		write(1, str, len);
	}
	return (info.width);//리턴값 정해주어야하고 precision도 신경써주어야한다.예외처리도
}

void	d_print_zero(int len) //get_arg_d 에서 사용
{
	putnchar(len, ' ');
}

void	d_print_right(t_format info, long d, int d_len, int minus)
{
	putnchar(info.width - info.precision - minus, ' ');
	if (minus == 1)
		write(1, "-", 1);
	putnchar(info.precision - d_len, '0');
	ft_putnbr(d, 10, DEC);
}

void	d_print_left(t_format info, long d, int d_len, int minus)
{
	if (minus == 1)
		write(1, "-", 1);
	putnchar(info.precision - d_len, '0');
	ft_putnbr_fd(d, 1);
	putnchar(info.width - info.precision - minus, ' ');

}


int 	get_arg_d(va_list ap, t_format info)
{
	int minus;
	int d;
	int d_len;

	minus = 0;
	d = va_arg(ap, int);
	if (d < 0)
		minus = 1;
	if (d == 0 && info.precision == 0)//정수가 0이고 precision 이 0 인경우
	{
		d_print_zero(info.width);
		return (info.width);
	}
	d_len = get_int_len(d);
	if (info.zero && info.precision <= -1)//아직 정확하게 모르겠다.
		info.precision = info.width - minus;
	if (info.precision <= -1 || info.precision < d_len)
		info.precision = d_len;
	if (info.left == 0)
		d_print_right(info, d, d_len, minus);
	else
		d_print_left(info, d, d_len, minus);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision + minus);
}

int 	get_arg_p(va_list ap, t_format info)
{
	void *p;

	p = va_arg(ap, void *);
	printf("%p\n", p);
	// 주소값 출력하는것 처리해주어야한다.
	return (1);
}

///////////////////////////// 함수 개수 초과

int		get_arg_u(va_list ap, t_format info)
{
	int len;
	return (0);
}

int		get_arg_x(va_list ap, t_format info)
{
	int len;
	return (0);
}

int		get_arg_X(va_list ap, t_format info)
{
	int len;
	return (0);
}

int		get_arg_per(va_list ap, t_format info)
{
	int len;

	len = 1;
	if (info.width > 1)
		len = info.width;
	if (info.left == 1)
	{
		write(1, "%", 1);
		putnchar(len - 1, ' ');
	}
	else
	{
		print_zero(info.zero, len - 1);
		write(1, "%", 1);
	}
	return (len);
}


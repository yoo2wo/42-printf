/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/26 17:43:59 by jayoo            ###   ########.fr       */
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
size_t	ft_strlen(const char *str);

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

int 	get_arg_d(va_list ap, t_format info)
{
	int d;
	int len;
	int wd;
	int flag;

	len = 0;
	d = va_arg(ap, int);
	if (d < 0)
		flag = 1; //음수이면 flag == 1;
	len += get_int_len(d);
	wd = len;
	if (info.width > len)
		wd = info.width;
	if (info.left == 1)
		ft_putnbr_fd(d, 1);
	print_zero(info.zero, wd - len);
	if (info.left == 0)
		ft_putnbr_fd(d, 1);
	return (wd);
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
int		get_arg_i(va_list ap, t_format info)
{
	int len;
	int d_len;
	int d;

	d = va_arg(ap, int);
	d_len = get_int_len(d);
	if (info.width > len)
		len = info.width;
	if (info.left == 1)
	{
		//precision을 신경서야해 d_len 보다 precision이 크면 0추가 아니라면 무시
		if (info.precision > d_len)
			putnchar(info.precision - d_len, '0');
		ft_putnbr_fd(d_len, 1);
		putnchar(' ', info.width - info.precision);
	}
	else
	{

	}


	return (0);
}

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


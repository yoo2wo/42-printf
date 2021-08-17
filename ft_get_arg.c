/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:27:30 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/17 16:11:20 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);

int 	get_arg_c(va_list ap, char *str, int  *i)
{
	char c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int 	get_arg_d(va_list ap, char *str, int  *i)
{
	int d;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, 1);
	return (1);
}

int 	get_arg_p(va_list ap, char *str, int  *i)
{
	void *p;

	p = va_arg(ap, void *);
	printf("%p\n", p);
	// 주소값 출력하는것 처리해주어야한다.
	return (1);
}

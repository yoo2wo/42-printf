/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:46:20 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/17 15:04:31 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	n = (n < 0) ? -n : n;
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], fd);
}

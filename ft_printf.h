/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:51:28 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/10 12:24:10 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define TYPE "cspdiuxX%"
# define DEC "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct 	s_format
{
	int			zero;
	int			left;
	int			width;
	int			dot;
	int			precision;
}				t_format;

int 	get_arg_c(va_list ap, t_format info);
int 	get_arg_s(va_list ap, t_format info);
int 	get_arg_p(va_list ap, t_format info);
int 	get_arg_d(va_list ap, t_format info);
int 	get_arg_i(va_list ap, t_format info);
int 	get_arg_u(va_list ap, t_format info);
int		get_arg_x(va_list ap, t_format info, char *base);
int 	get_arg_per(t_format info);

void	rec_p(unsigned long nbr, int len, char *base);
void	ft_putnbr_p(unsigned long nbr, int len, char *base);
void	p_print_right(t_format info, unsigned long num, int size);
void	p_print_left(t_format info, unsigned long num, int size);

size_t	ft_strlen(const char *str);
void	putnchar(int num, char c);
void	ft_putchar(const char c);
void	ft_putstr(const char *s);
void	rec_nbr(long long nbr, int len, char *base);
void	ft_putnbr(long long n, int len, char *base);
int		num_size(long long num, int base_len);

void	d_print_right(t_format info, long d, int d_len, int minus);
void	d_print_left(t_format info, long d, int d_len, int minus);
void	print_zero(int zero, int len);

int		ft_atoi(const char *str);
void	set_format_star(va_list ap, t_format *info);
void	set_format_num(t_format *info, char *str, int *i);
int		set_format(va_list ap, char *str, int *i);

void		init_info(t_format *info);
int		valid_char(char c, char *str);
int		get_arg(va_list ap, t_format info, char c);

void	x_print_left(t_format info, unsigned long num, int size, char *base);
void	x_print_right(t_format info, unsigned long num, int size, char *base);
#endif

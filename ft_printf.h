/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:51:28 by jayoo             #+#    #+#             */
/*   Updated: 2021/09/08 17:06:41 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define TYPE "cspdiuxX%"
# define DEC "0123456789"

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
int 	get_arg_x(va_list ap, t_format info);
int 	get_arg_X(va_list ap, t_format info);
int 	get_arg_per(va_list ap, t_format info);

int		ft_atoi(const char *str);

#endif

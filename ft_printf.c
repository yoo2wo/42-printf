/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoo <jayoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:25 by jayoo             #+#    #+#             */
/*   Updated: 2021/08/16 16:45:57 by jayoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *types, ...);

int		ft_printf(const char *types, ...)
{
	va_list ap; //가변 인자 목록
	int i = 0;
	int arr[5];

	va_start(ap, types); //문자열을 넣으면 문자의 개수를 구해 포인터를 설정한다.
	while (types[i] != '\0')
	{
		arr[i] = va_arg(ap, int);
		i++;
	}
	printf("%d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2],arr[3],arr[4]);
	printf("%s", types);
	va_end(ap);
	return 0;
}

int main()
{
	ft_printf("start", 1,2,3,4,5);
	return 0;
}

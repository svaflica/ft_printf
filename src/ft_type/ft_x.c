/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:58:01 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/01 14:01:54 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include <stdio.h>

static int		ft_type_x(t_param list, char *i)
{
	int		size;
	int		tmp;

	size = 0;
	tmp = ft_strlen(i);
	printf("%d\n", tmp);
}
int		ft_x(t_param list, va_list ap)
{
	if (list.length == 0)
		return (ft_type_o(list,
				ft_itoa_base((unsigned int)va_arg(ap, int), 16)));
	else if (list.length == 'l')
		return (ft_type_o(list,
				ft_itoa_base((unsigned long)va_arg(ap, int), 16)));
	else if (list.length == 'l' + 'l')
		return (ft_type_o(list,
				ft_itoa_base((unsigned long long)va_arg(ap, int), 16)));
	else if (list.length == 'h')
		return ((ft_type_o(list,
				ft_itoa_base((unsigned short)va_arg(ap, int), 16))));
	else if (list.length == 'h' + 'h')
		return (ft_type_o(list,
				ft_itoa_base((unsigned char)va_arg(ap, int), 16)));
	return (0);
}

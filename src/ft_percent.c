/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/25 13:44:12 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_type(va_list ap, char **str, t_param list)
{
	if (**str == 'c')
		return (ft_c(list, va_arg(ap, int)));
	else if (**str == 's')
		return (ft_s(list, va_arg(ap, char *)));
//	else if (**str == 'p')
//		return (ft_p(list, va_arg(ap, void *)));

	return (-1);
}

size_t			ft_percent(va_list ap, char **str, t_param list)
{
	if (**str == '%')
	{
		ft_putchar('%');
		*str += 1;
	}
	else
	{
		ft_param_add(&list, str);
		return (ft_type(ap, str, list));
	}
}

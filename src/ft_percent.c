/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/01 13:54:10 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_type(va_list ap, char **str, t_param list)
{
	if (**str == 'c' || **str == 'C')
		return (ft_c(list, (char)va_arg(ap, int)));
	else if (**str == 's')
		return (ft_s(list, (char *)va_arg(ap, char *)));
	else if (**str == 'o')
		return (ft_o(list, ap));
	else if (**str == 'p')
		return (ft_p(list, va_arg(ap, void *)));
	else if (**str == 'd' || **str == 'i')
		return (ft_d(list, ap));
	else if (**str == 'u')
		return (ft_u(list, ap));
	else if (**str == 'x')
		return (ft_x(list, ap));
	else if (**str == '%')
		return (ft_prcnt(list));
	else
		return (ft_print_symb(**str, 1));
	return (0);
}

size_t			ft_percent(va_list ap, char **str, t_param list)
{
	ft_param_add(&list, str);
	return (ft_type(ap, str, list));
}

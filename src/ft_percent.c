/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/09 14:45:56 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_type(va_list ap, char **str, t_param list, t_buf *buf)
{
	if (**str == 'C' || (**str == 'c' && list.length == 'l'))
		ft_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
	else if (**str == 'c')
		ft_c(list, (char)va_arg(ap, int), buf);
	else if (**str == 'S' || (**str == 's' && list.length == 'l'))
		ft_s_up(list,(wchar_t *)va_arg(ap, wchar_t *), buf);
	else if (**str == 's')
		ft_s(list, (char *)va_arg(ap, char *), buf);
	else if (**str == 'o')
		ft_o(list, ap, buf);
	else if (**str == 'O')
		ft_o_up(list, ap, buf);
	else if (**str == 'p')
		ft_p(list, va_arg(ap, void *), buf);
	else if (**str == 'd' || **str == 'i')
		ft_d(list, ap, buf);
	else if (**str == 'D')
		ft_d_up(list, ap, buf);
	else if (**str == 'u')
		ft_u(list, ap, buf);
	else if (**str == 'U')
		ft_u_up(list, ap, buf);
	else if (**str == 'x')
		ft_x(list, ap, buf);
	else if (**str == 'X')
		ft_x_up(list, ap, buf);
	else if (**str == '%')
		ft_prcnt(list, buf);
	else if (**str == 'f')
		ft_f(list, ap, buf);
	else if (**str)
		ft_c(list, **str, buf);
}

void			ft_percent(va_list ap, char **str, t_param list, t_buf *buf)
{
	ft_param_add(&list, str, ap);
	ft_type(ap, str, list, buf);
}

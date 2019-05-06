/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/06 15:33:45 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_type(va_list ap, char **str, t_param list, t_buf *buf)
{
	if (**str == 'c')
		ft_c(list, (char)va_arg(ap, int), buf);
	else if (**str == 'C')
		ft_c_up(list, (unsigned long long)va_arg(ap, unsigned long long), buf);
	else if (**str == 's' || **str == 'S')
		ft_s(list, (char *)va_arg(ap, char *), buf);
	else if (**str == 'o')
		ft_o(list, ap, buf);
	else if (**str == 'p')
		ft_p(list, va_arg(ap, void *), buf);
	else if (**str == 'd' || **str == 'i')
		ft_d(list, ap, buf);
	else if (**str == 'u')
		ft_u(list, ap, buf);
	else if (**str == 'x')
		ft_x(list, ap, buf);
	else if (**str == 'X')
		ft_x_up(list, ap, buf);
	else if (**str == '%')
		ft_prcnt(list, buf);
	else if (**str)
		ft_buf_add_c(buf, **str);
}

void			ft_percent(va_list ap, char **str, t_param list, t_buf *buf)
{
	ft_param_add(&list, str, ap);
	ft_type(ap, str, list, buf);
}

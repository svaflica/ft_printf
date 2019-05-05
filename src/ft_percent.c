/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:53:56 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/05 19:21:16 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_type(va_list ap, char **str, t_param list, t_buf *buf)
{
	if (**str == 'c' || **str == 'C')
		return (ft_c(list, (unsigned long long)va_arg(ap, unsigned long long),
				buf));
	else if (**str == 's' || **str == 'S')
		return (ft_s(list, (char *)va_arg(ap, char *), buf));
	else if (**str == 'o')
		return (ft_o(list, ap, buf));
	else if (**str == 'p')
		return (ft_p(list, va_arg(ap, void *), buf));
	else if (**str == 'd' || **str == 'i')
		ft_d(list, ap, buf);
	else if (**str == 'u')
		return (ft_u(list, ap, buf));
	else if (**str == 'x')
		return (ft_x(list, ap, buf));
	else if (**str == '%')
		return (ft_prcnt(list, buf));
	else
		return (ft_buf_add_c(buf, **str));
}

void			ft_percent(va_list ap, char **str, t_param list, t_buf *buf)
{
	ft_param_add(&list, str, ap);
	ft_type(ap, str, list, buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 08:41:17 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/05 17:12:43 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_buf		buf;
	t_param		list;
	int			res;

	va_start(ap, str);
	ft_buf_new(&buf);
	ft_param_nul(&list);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_percent(ap, &str, list, &buf);
		}
		else /* if (*str == '{')
			ft_detect_color(&str, &buf);
		else */
			ft_buf_add_c(&buf, *str);
		str++;
	}
	res = ft_do_buf_empty(&buf);
	va_end(ap);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:16:42 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/09 13:49:50 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		ft_zero(t_param list, int len, t_buf *buf)
{
	if (list.minus == 1)
	{
		ft_buf_add_s(buf, "0x", 1);
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
		if (list.width > list.precision && list.width > len &&
			list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.width - list.precision - 2, ' '), 0);
		if (list.width > list.precision && list.width > len &&
			list.precision < len - 2)
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
	else
	{
		if (list.width > list.precision && list.width > len)
		{
			(list.precision > len - 2) ? ft_buf_add_s(buf, ft_memnew(list.width
			- list.precision - 2, ' '), 0) : ft_buf_add_s(buf, ft_memnew(list.width
			- len, ' '), 0);
		}
		ft_buf_add_s(buf, "0x", 1);
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	}
}

static void		minus_pos(t_param list, char *str, int len, t_buf *buf)
{
	ft_buf_add_s(buf, "0x", 1);
	if (list.precision > len - 2)
		ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	ft_buf_add_s(buf, str, 0);
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.width - list.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
}

static void		minus_neg(t_param list, char *str, int len, t_buf *buf)
{
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.width - list.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
	ft_buf_add_s(buf, "0x", 1);
	if (list.precision > len - 2)
		ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	ft_buf_add_s(buf, str, 0);
}

void			ft_p(t_param list, void *ptr, t_buf *buf)
{
	long long		tmp;
	char			*str;
	int				len;

	tmp = (unsigned long long)ptr;
	str = ft_itoa_base_ll(tmp, 16);
	len = ft_strlen(str) + 2;
	if (*str == '0' && len == 3 && list.precision > -1)
		ft_zero(list, len - 1, buf);
	else if (list.minus == 1)
		minus_pos(list, str, len, buf);
	else
		minus_neg(list, str, len, buf);
	// free(str);
}

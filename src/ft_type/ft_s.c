/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:30:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/05/09 10:31:46 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		prec_pos(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
        if (list.width > (tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision) - (tmp == 0 ? list.precision : 0), '0'));
		else if (list.width > (tmp < list.precision ? tmp : list.precision) && s != NULL)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision)/*  - (tmp == 0 ? list.precision : 0) */, ' '));
		if (s != NULL)
			ft_buf_add_ns(buf, s, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_ns(buf, "(null)", list.precision);
	}
	else
	{
		if (s != NULL)
			ft_buf_add_ns(buf, s, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_ns(buf, "(null)", list.precision);
        if (list.width > (tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision) - (tmp == 0 ? list.precision : 0), '0'));
		else if (list.width > (tmp < list.precision ? tmp : list.precision) && s != NULL)
			ft_buf_add_s(buf, ft_memnew(list.width - (tmp < list.precision ? tmp : list.precision)/*  - (tmp == 0 ? list.precision : 0) */, ' '));
	}
}

static void		prec_neg(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > tmp && list.zero == 0 && s != NULL)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
		else if (list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'));
		if (s != NULL)
			ft_buf_add_s(buf, s);
		else
			ft_buf_add_s(buf, "(null)");
	}
	else
	{
		if (s != NULL)
			ft_buf_add_s(buf, s);
		else
			ft_buf_add_s(buf, "(null)");
		if (list.width > tmp && list.zero == 0 && s != NULL)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '));
		else if (list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'));
	}
}

void		ft_s(t_param list, char *s, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(s);
	if (list.precision > -1)
		prec_pos(list, s, tmp, buf);
	else
		prec_neg(list, s, tmp, buf);
}
